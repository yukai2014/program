/*
 * CpuScheduler.h
 *
 *  Created on: Apr 27, 2015
 *      Author: wangli,yukai
 */

#ifndef SIMPLETHREADPOOL_CPUSCHEDULER_H_
#define SIMPLETHREADPOOL_CPUSCHEDULER_H_

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
#include "Logs.h"

const int MAX_CPU_NUM = 1000;

/* get number of sockets on this machine */
static int GetNumberOfSockets() {
  assert(numa_available() >= 0 && "numa functions unavailable");
  return numa_max_node() + 1;
}

/* get the total number of cores */
static int GetNumberOfCpus() { return sysconf(_SC_NPROCESSORS_CONF); }

/* get the id of the cpu running the current thread */
static int GetCurrentCpuAffinity() {
  cpu_set_t mask;
  if (sched_getaffinity(0, sizeof(mask), &mask) < 0) {
    printf("ERROR:%s\n", strerror(errno));
    assert(false && "can not get cpu affility");
    return -1;
  }
  for (int i = 0; i < GetNumberOfCpus(); i++) {
    if (CPU_ISSET(i, &mask)) {
      return i;
    }
  }
  assert(false && "can not get cpu affility");
  return -1;
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
    assert(false && "can not set cpu affility");
    return false;
  }
  return true;
}

/* get the NUMA socket index of the specified thread */
static int GetSocketAffility(int cpu) {
  assert(cpu >= 0 && "cpu is unavailable");
  return numa_node_of_cpu(cpu);
}

/* get the NUMA socket index of the current thread */
static int GetCurrentSocketAffility() {
  int current_cpu = GetCurrentCpuAffinity();
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
