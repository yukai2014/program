/*
 * Test.cpp
 *
 *  Created on: 2014-8-18
 *      Author: imdb
 */

#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include "./cpu_scheduler.h"
#include "./thread_pool.h"
using namespace std;

const int thread_count = 2;

void *func(void *a) {
  int num = *static_cast<int *>(a);
  cout << num << endl;
  return NULL;
}

void *ShowSocketAndCpu(void *no_means) {
  cout << "Current cpu is: ";
  for (auto it : GetCurrentCpuAffinity()) cout << it << "\t";
  cout << endl << "Current node is: ";
  for (auto it : GetCurrentSocketAffility()) cout << it << "\t";
  cout << endl;

  //  int temp = 1;
  //  while (1) {
  //    temp += temp % 10;
  //  }
  usleep(1200 * 1000);
  return NULL;
}
void *NewThreadAndSleepForever(void *arg) {
  ThreadPool *tp = static_cast<ThreadPool *>(arg);
  tp->AddTask(ShowSocketAndCpu, NULL);
  while (1) sleep(100);
}

int main() {
  int task_count = 4;
  int num = 10000;
  timeval start_time;
  gettimeofday(&start_time, NULL);
  cout << "start" << endl;
  cout << "NUMA is " << (numa_available() >= 0) ? "available" : "unavailable";
  cout << endl;
  {
    pthread_t p;
    pthread_create(&p, NULL, ShowSocketAndCpu, NULL);
    usleep(500);
  }

  ThreadPool *tp = new ThreadPool();
  if (tp->Init(thread_count) == 0) {
    cout << "init failed" << endl;
  }
  while (task_count--) {
    tp->AddTask(ShowSocketAndCpu, NULL);
    usleep(100);
  }
  sleep(3);
  tp->Destroy(tp);

  cout << "===========================" << endl;
  if (tp->Init(thread_count) == 0) {
    cout << "init failed" << endl;
  }
  int cpu_num = GetNumberOfCpus();
  int cpu = 0;
  for (int i = 0; i < 3; ++i) {
    tp->AddTaskInCpu(ShowSocketAndCpu, NULL, (++cpu) % cpu_num);
    usleep(100);
  }
  sleep(3);
  tp->Destroy(tp);
  // usleep(3000000);
  cout << "===========================" << endl;
  if (tp->Init(thread_count) == 0) {
    cout << "init failed" << endl;
  }
  task_count = 130;
  int node_num = GetNumberOfSockets();
  int node = 0;
  for (int i = 0; i < task_count; ++i) {
    tp->AddTaskInSocket(ShowSocketAndCpu, NULL, (node++) % node_num);
    usleep(i % 5 * 100 * 1000);
  }
  sleep(20);
  tp->Destroy(tp);

  cout << "===========================deadlock" << endl;
  if (tp->Init(thread_count) == 0) {
    cout << "init failed" << endl;
  }
  task_count = 40;
  node_num = GetNumberOfSockets();
  node = 0;
  for (int i = 0; i < task_count; ++i) {
    tp->AddTaskInSocket(NewThreadAndSleepForever, tp, (node++) % node_num);
    usleep(i % 5 * 100 * 1000);
  }
  sleep(20);
  tp->Destroy(tp);

  timeval finish_time;
  gettimeofday(&finish_time, NULL);
  cout << " use "
       << (finish_time.tv_usec - start_time.tv_usec) / 1000.0 +
              (finish_time.tv_sec - start_time.tv_sec) * 1000 << " ms" << endl;

  return 0;
}
