/*
 * ThreadPool.h
 *
 *  Created on: 2014-8-17
 *      Author: imdb
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <queue>
#include <vector>

#include "../common/Log.h"
#include "./logs.h"
// #define __USE_GNU		//启用CPU_ZERO等相关的宏
using namespace std;

class Task;

class ThreadPool {
 public:
  typedef void *(*void_function)(void *);

 public:
  ThreadPool();
  virtual ~ThreadPool();

  bool Init(int thread_count_in_pool);
  // parameter void* a can't be a class, because delete void * won't execute
  // destructor function
  void AddTask(void_function f, void *a);
  void AddTaskInSocket(void_function f, void *a, int socket_index);
  void AddTaskInSocket(void_function f, void *a, vector<int> socket_indexs);
  void AddTaskInCpu(void_function f, void *arg, int cpu_index);
  void AddTaskInCpu(void_function f, void *arg, vector<int> cpu_indexs);
  void Destroy(ThreadPool *tp);

 private:
  void AddTask(Task *t);
  void AddDestroyTask();
  void HandleTask(ThreadPool *thread_pool);
  static void *MonitorThreadExec(void *arg);
  static void *ThreadExec(void *arg);
  static void *TempThreadExec(void *arg);

 private:
  //  pthread_cond_t free_thread_cond;
  //  pthread_mutex_t cond_lock;
  //
  //  attfinity_start_cpu;

  sem_t undo_task_sem_;  // undo task count

  pthread_t *thread_list_ = NULL;
  pthread_t monitor_thread_;

  queue<Task *> task_queue_;
  pthread_mutex_t task_queue_lock_;

  int base_thread_count_;
  int free_thread_count_;
  int max_thread_count_;
  volatile int current_thread_count_;
  //  pthread_mutex_t free_thread_count_lock_;

  int task_count_;
  int undo_task_count_;
  bool is_destroy_ = false;
  //  pthread_mutex_t undo_task_count_lock_;
};

#endif /* THREADPOOL_H_ */
