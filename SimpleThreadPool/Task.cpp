/*
 * Task.cpp
 *
 *  Created on: May 9, 2015
 *      Author: yukai
 */


#include "Task.h"

#define SPECIFY_CPU

int NumaSensitiveTask::cur[] = {0};

/*
 *  get old binded CPU and rebind new CPU in specify socket,
 *  run function f,
 *  bind to old CPU again
 */
void NumaSensitiveTask::Run() {
	int old_cpu = getCurrentCpuAffility();
//	Logs::log("Before bind socket:\tCurrent cpu is: %d\tCurrent node is: %d\n", getCurrentCpuAffility(), getCurrentSocketAffility());
#ifdef SPECIFY_CPU
	bitmask* bm = numa_allocate_cpumask();
	numa_bitmask_clearall(bm);

	// get next CPU in specified node and bind to it
	assert(node_index_ < getNumberOfSockets() && node_index_ >= 0
			&& "node_index_ is unavailable");
	if (numa_node_to_cpus(node_index_, bm) != 0) {
		Logs::elog("ERROR:%s",strerror(errno));
		assert(false && "numa_node_to_cpus() failed");
	}
	int cpu_index = __sync_fetch_and_add(&(cur[node_index_]), 1)%getNumberOfCpus();
	while (numa_bitmask_isbitset(bm, cpu_index) != 1){
		cpu_index = __sync_fetch_and_add(&(cur[node_index_]), 1)%getNumberOfCpus();
	}

	setCpuAffility(cpu_index);
#else
	struct bitmask* bm = numa_allocate_nodemask();
	numa_bitmask_clearall(bm);
	numa_bitmask_setbit(bm, node_index_);
//	numa_bind(bm);
//	numa_run_on_node(node_index_);	// bind to the first CPU in this numa node
//	Logs::log("After numa_run_on_ndoe");

	numa_run_on_node_mask_all(bm);	// bind to the first CPU in this numa node, same as numa_run_on_node()
//	Logs::log("After numa_run_on_node_mask_all");
#endif
	(*func_)(arg_);

	numa_free_nodemask(bm);
	// restore old binding
	setCpuAffility(old_cpu);
//	Logs::log("After restor:\tCurrent cpu is: %d\tCurrent node is: %d\n", getCurrentCpuAffility(), getCurrentSocketAffility());

}

void NumaSensitiveTask::BindSocket(int node_index) {

}


