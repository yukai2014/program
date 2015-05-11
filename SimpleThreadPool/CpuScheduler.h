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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <numa.h>
#include <assert.h>
#include <errno.h>

/* get number of sockets on this machine */
static int getNumberOfSockets(){
	assert(numa_available() >= 0 && "numa functions unavailable");
	return numa_max_node()+1;
}

/* get the total number of cores */
static int getNumberOfCpus(){
	return  sysconf(_SC_NPROCESSORS_CONF);
}

/* get the id of the cpu running the current thread */
static int getCurrentCpuAffility(){
	cpu_set_t mask;
	if(sched_getaffinity(0,sizeof(mask),&mask)<0) {
		printf("ERROR:%s\n", strerror(errno));
		assert(false && "can not get cpu affility");
		return -1;
	}
	for(int i=0;i<getNumberOfCpus();i++){
		 if (CPU_ISSET(i, &mask)) {
			 return i;
		}
	}
	assert(false && "can not get cpu affility");
	return -1;
}

/* bind the current thread on the specified cpu*/
static bool setCpuAffility(int cpu){
	assert(cpu >= 0 && "cpu is unavailable");
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(cpu,&mask);
	if(sched_setaffinity(0,sizeof(mask),&mask)<0) {
		printf("ERROR:%s\n", strerror(errno));
		assert(false && "can not set cpu affility");
		return false;
	}
	return true;
}

/* get the NUMA socket index of the specified thread */
static int getSocketAffility(int cpu){
	assert(cpu >= 0 && "cpu is unavailable");
	return numa_node_of_cpu(cpu);
}

/* get the NUMA socket index of the current thread */
static int getCurrentSocketAffility(){
	int current_cpu=getCurrentCpuAffility();
	return getSocketAffility(current_cpu);
}

static int GetNextCPUinSocket(int socket_index) {
//	int new_node_cur = new int[getNumberOfSockets()];
	assert(false);
}

#endif /* SIMPLETHREADPOOL_CPUSCHEDULER_H_ */
