/*
 * Test.cpp
 *
 *  Created on: 2014-8-18
 *      Author: imdb
 *
 *
 *      how to use: command--->	g++ -lpthread -g -o test_zl
 *ThreadPoolTest.cpp Thread_Pool.cpp Test.cpp Thread_Pool.cpp Thread_Pool.h -D
 *zl
 *      									g++
 *-lpthread
 *-g
 *-o test_yk ThreadPoolTest.cpp Thread_Pool.cpp Test.cpp Thread_Pool.cpp
 *Thread_Pool.h -D yk
 */

#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include "./cpu_scheduler.h"
#include "./thread_pool.h"
using namespace std;

const int thread_count = 6;

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
    sleep(5);
  }

  ThreadPool *tp = new ThreadPool();
  if (tp->Init(thread_count) == 0) {
    cout << "init failed" << endl;
  }
  while (task_count--) {
    tp->AddTask(ShowSocketAndCpu, NULL);
    sleep(1);
  }
  tp->Destroy(tp);

  cout << "===========================" << endl;
  if (tp->Init(thread_count) == 0) {
    cout << "init failed" << endl;
  }
  int cpu_num = GetNumberOfCpus();
  int cpu = 0;
  for (int i = 0; i < 3; ++i) {
    tp->AddTaskInCpu(ShowSocketAndCpu, NULL, (++cpu) % cpu_num);
    sleep(1);
  }

  tp->Destroy(tp);
  // usleep(3000000);
  cout << "===========================" << endl;
  if (tp->Init(thread_count) == 0) {
    cout << "init failed" << endl;
  }
  task_count = 10;
  int node_num = GetNumberOfSockets();
  int node = 0;
  for (int i = 0; i < task_count; ++i) {
    tp->AddTaskInSocket(ShowSocketAndCpu, NULL, (node++) % node_num);
    sleep(1);
  }
  tp->Destroy(tp);

  timeval finish_time;
  gettimeofday(&finish_time, NULL);
  cout << " use "
       << (finish_time.tv_usec - start_time.tv_usec) / 1000.0 +
              (finish_time.tv_sec - start_time.tv_sec) * 1000 << " ms" << endl;

  return 0;
}
