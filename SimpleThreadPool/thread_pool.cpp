/*
 * ThreadPool.cpp
 *
 *  Created on: 2014-8-17
 *      Author: imdb
 *
 *      TODO: if task is more than thread, create some thread that execute
 *function once
 *		可以试着添加负载均衡
 *		如果每个线程需要分配内存，为了节省内存，可以设置线程第一次运行才分配内存，优先让已经分配到内存的线程运行
 *
 */
#include "./thread_pool.h"

#include <semaphore.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <vector>

#include "./task.h"
#include "../common/memory_usage.h"

// cannot open, otherwise results in unknown behavior
// #define UNBLOCKED_JOIN

ThreadPool::ThreadPool() {}

ThreadPool::~ThreadPool() {
  if (thread_list_ != NULL) Destroy(this);
}

bool ThreadPool::Init(int thread_count_in_pool) {
  bool success = true;
  base_thread_count_ = thread_count_in_pool;
  pthread_mutex_init(&task_queue_lock_, NULL);
  sem_init(&undo_task_sem_, 0, 0);  // init semaphore
  thread_list_ = static_cast<pthread_t *>(
      malloc(2 * base_thread_count_ * sizeof(pthread_t)));
  while (!task_queue_.empty()) {
    DeletePtr(task_queue_.back());
    task_queue_.pop();
  }

  if (pthread_create(&monitor_thread_, NULL, MonitorThreadExec, this) !=
      0) {  // if any failed, return false
    cout << "ERROR: create monitor thread failed!" << endl;
    return false;
  }
  for (int i = 0; i < base_thread_count_; ++i) {
    if (pthread_create(&thread_list_[i], NULL, ThreadExec, this) !=
        0) {  // if any failed, return false
      cout << "ERROR: create pthread failed!" << endl;
      return false;
    }
    ++current_thread_count_;
  }
  assert(current_thread_count_ == base_thread_count_);
  return true;
}

void ThreadPool::AddTask(Task *t) {
  pthread_mutex_lock(&task_queue_lock_);
  task_queue_.push(t);
  pthread_mutex_unlock(&task_queue_lock_);

  sem_post(&undo_task_sem_);
}

void ThreadPool::AddTask(void_function f, void *a) {
  Task *task = new Task(f, a);
  AddTask(task);
}

void ThreadPool::AddDestroyTask() {
  DestroyTask *task = new DestroyTask();
  AddTask(task);
}

void ThreadPool::AddTaskInSocket(void_function f, void *a, int socket_index) {
  if (numa_available() < 0) {
    Logs::elog("numa_* functions unavailable\n");
    assert(false);
  }
  NumaSensitiveTask *task = new NumaSensitiveTask(f, a, socket_index);
  AddTask(task);
}

void ThreadPool::AddTaskInSocket(void_function f, void *a,
                                 vector<int> socket_indexs) {
  if (numa_available() < 0) {
    Logs::elog("numa_* functions unavailable\n");
    assert(false);
  }
  NumaSensitiveTask *task = new NumaSensitiveTask(f, a, socket_indexs);
  AddTask(task);
}

void ThreadPool::AddTaskInCpu(void_function f, void *arg, int cpu_index) {
  CpuSensitiveTask *task = new CpuSensitiveTask(f, arg, cpu_index);
  AddTask(task);
}

void ThreadPool::AddTaskInCpu(void_function f, void *arg,
                              vector<int> cpu_indexs) {
  CpuSensitiveTask *task = new CpuSensitiveTask(f, arg, cpu_indexs);
  AddTask(task);
}

void ThreadPool::HandleTask(ThreadPool *thread_pool) {
  sem_wait(&(thread_pool->undo_task_sem_));
  Task *task = NULL;

  pthread_mutex_lock(&(thread_pool->task_queue_lock_));
  if (!thread_pool->task_queue_.empty()) {
    task = thread_pool->task_queue_.front();
    thread_pool->task_queue_.pop();
  }
  pthread_mutex_unlock(&(thread_pool->task_queue_lock_));

  if (task != NULL) {
    Logs::log("thread (id=%ld,offset=%lx) in thread pool is executing..\n",
              syscall(__NR_gettid), pthread_self());
    task->Run();
    Logs::log(
        "thread (id=%ld,offset=%lx) in thread pool finished executing..\n",
        syscall(__NR_gettid), pthread_self());
    DeletePtr(task);
  }
}

void *ThreadPool::ThreadExec(void *arg) {
  Logs::log("a new thread is added into pool.");
  ThreadPool *thread_pool = static_cast<ThreadPool *>(arg);
  Task *task = NULL;

  // every thread execute a endless loop, waiting for task, and exit when
  // receive a task with end member of 'true'
  while (1) {
    HandleTask(thread_pool);
  }
  pthread_exit(NULL);
  return NULL;
}

void *ThreadPool::TempThreadExec(void *arg) {
  Logs::log("a temporary thread is created.");
  ThreadPool *thread_pool = static_cast<ThreadPool *>(arg);
  Task *task = NULL;

  HandleTask(thread_pool);
  return NULL;
}

void *ThreadPool::MonitorThreadExec(void *arg) {
  usleep(500 * 1000);
  ThreadPool *tp = static_cast<ThreadPool *>(arg);
  if (NULL == tp->thread_list_) return NULL;  // which means pool is destroyed
  static int too_many_task_times = 0;
  static int expand_thread_times = 0;
  int undo_task_count;
  sem_getvalue(&(tp->undo_task_sem_), &undo_task_count);

  if (undo_task_count > 0) {
    if (++too_many_task_times > 3) {
      int to_expand_thread_count = (undo_task_count + 1) / 2;
      if (++expand_thread_times > 3 &&
          current_thread_count_ < base_thread_count_ * 2 - 1) {
        if (NULL == tp->thread_list_)
          return NULL;  // which means pool is destroyed
        pthread_create(&thread_list_[++current_thread_count_], NULL, ThreadExec,
                       tp);
        expand_thread_times = 0;
        --to_expand_thread_count;  // because of adding one thread perpetually
      }
      for (int i = 0; i < to_expand_thread_count; ++i) {
        if (NULL == tp->thread_list_)
          return NULL;  // which means pool is destroyed
        pthread_t temp;
        pthread_create(&temp, NULL, TempThreadExec, tp);
      }
      too_many_task_times = 0;
    }
  } else {
    too_many_task_times = 0;
    expand_thread_times = 0;
  }

  return NULL;
}

void ThreadPool::Destroy(ThreadPool *tp) {
  // destroy every thread by sending destroy task to everyone
  for (int i = 0; i < tp->current_thread_count_; ++i) {
    tp->AddDestroyTask();
  }
#ifndef UNBLOCKED_JOIN
  for (int i = 0; i < tp->current_thread_count_; ++i) {
    pthread_join(tp->thread_list_[i], NULL);
  }
#endif
  DeletePtr(tp->thread_list_);
  while (!tp->task_queue_.empty()) {
    Task *temp = tp->task_queue_.front();
    tp->task_queue_.pop();
    DeletePtr(temp);
  }
  sem_destroy(&tp->undo_task_sem_);
  pthread_mutex_destroy(&tp->task_queue_lock_);
  pthread_join(tp->monitor_thread_, NULL);
}
