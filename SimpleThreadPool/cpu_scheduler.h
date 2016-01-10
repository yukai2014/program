/*
 * CpuScheduler.h
 *
 *  Created on: Apr 27, 2015
 *      Author: wangli,yukai
 */

#ifndef SIMPLETHREADPOOL_CPUSCHEDULER_H_
#define SIMPLETHREADPOOL_CPUSCHEDULER_H_
#include <vector>

using std::vector;

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <numa.h>
#include <assert.h>
#include <errno.h>
#include "./logs.h"

const int MAX_CPU_NUM = 1000;

/* get number of sockets on this machine */
static int GetNumberOfSockets() {
  assert(numa_available() >= 0 && "numa functions unavailable");
  return numa_max_node() + 1;
}

/* get the total number of cores */
static int GetNumberOfCpus() { return sysconf(_SC_NPROCESSORS_CONF); }

/* get the ids of the cpu running the current thread */
static vector<int> GetCurrentCpuAffinity() {
  std::vector<int> bind_cpus;
  cpu_set_t mask;
  if (sched_getaffinity(0, sizeof(mask), &mask) < 0) {
    printf("ERROR:%s\n", strerror(errno));
    assert(false && "can not get cpu affinity");
    return bind_cpus;
  }
  for (int i = 0; i < GetNumberOfCpus(); i++) {
    if (CPU_ISSET(i, &mask)) {
      bind_cpus.push_back(i);
    }
  }
  return bind_cpus;
}

/* bind the current thread on the specified cpu*/
static bool SetCpuAffinity(int cpu) {
  assert(cpu >= 0 && "cpu is unavailable");
  cpu_set_t mask;
  CPU_ZERO(&mask);
  CPU_SET(cpu, &mask);
  // sched_setaffinity only bind thread's CPU not process
  if (sched_setaffinity(0, sizeof(mask), &mask) < 0) {
    printf("ERROR:%s\n", strerror(errno));
    assert(false && "can not set cpu affinity");
    return false;
  }
  return true;
}

/* bind the current thread on the specified cpus*/
static bool SetCpuAffinity(vector<int> cpu) {
  assert(cpu.size() >= 0 && "cpu is unavailable");
  cpu_set_t mask;
  CPU_ZERO(&mask);
  for (int i = 0; i < cpu.size(); ++i) CPU_SET(cpu[i], &mask);
  // sched_setaffinity only bind thread's CPU not process
  if (sched_setaffinity(0, sizeof(mask), &mask) < 0) {
    printf("ERROR:%s\n", strerror(errno));
    return false;
  }
  return true;
}

/* get the NUMA socket index of the specified thread */
static vector<int> GetSocketAffility(vector<int> cpu) {
  assert(cpu.size() > 0 && "cpu is unavailable");
  vector<int> sockets;
  int node;
  for (int i = 0; i < cpu.size(); ++i) {
    if (-1 != (node = numa_node_of_cpu(cpu[i])))
      sockets.push_back(node);
    else
      assert(false && "value in cpu is invalid");
  }
  return sockets;
}

/* get the NUMA socket index of the current thread */
static vector<int> GetCurrentSocketAffility() {
  vector<int> current_cpu = GetCurrentCpuAffinity();
  return GetSocketAffility(current_cpu);
}

/*
 * no-locking support for multi-thread
 * get the next cpu index in socket specified by socket_index
 */
static int GetNextCPUinSocket(int socket_index) {
  static volatile int cur[MAX_CPU_NUM] = {
      0};  // indicate current CPU in every node

  bitmask* bm = numa_allocate_cpumask();
  numa_bitmask_clearall(bm);

  // get next CPU in specified node and bind to it
  assert(socket_index < GetNumberOfSockets() && socket_index >= 0 &&
         "node_index_ is unavailable");
  if (numa_node_to_cpus(socket_index, bm) != 0) {
    Logs::elog("ERROR:%s", strerror(errno));
    assert(false && "numa_node_to_cpus() failed");
  }
  int cpu_index =
      __sync_fetch_and_add(&(cur[socket_index]), 1) % GetNumberOfCpus();
  while (numa_bitmask_isbitset(bm, cpu_index) != 1) {
    cpu_index =
        __sync_fetch_and_add(&(cur[socket_index]), 1) % GetNumberOfCpus();
  }

  numa_free_cpumask(bm);
  return cpu_index;
  assert(false);
}

static int GetNextSocket() {
  static volatile int index = 0;
  int socket_num = GetNumberOfSockets();
  int socket_index = (__sync_fetch_and_add(&index, 1)) % socket_num;
  return socket_index;
}

#endif /* SIMPLETHREADPOOL_CPUSCHEDULER_H_ */
