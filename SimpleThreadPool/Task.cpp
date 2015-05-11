/*
 * Task.cpp
 *
 *  Created on: May 9, 2015
 *      Author: yukai
 */


#include "Task.h"

#define SPECIFY_CPU

/*
 *  get old binded CPU and rebind new CPU in specify socket,
 *  run function f,
 *  bind to old CPU again
 */
void NumaSensitiveTask::Run() {
	int old_cpu = getCurrentCpuAffility();
//	Logs::log("Before bind socket:\tCurrent cpu is: %d\tCurrent node is: %d\n", getCurrentCpuAffility(), getCurrentSocketAffility());
#ifdef SPECIFY_CPU
	int cpu_index = GetNextCPUinSocket(node_index_);
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

	// restore old binding
	setCpuAffility(old_cpu);
//	Logs::log("After restor:\tCurrent cpu is: %d\tCurrent node is: %d\n", getCurrentCpuAffility(), getCurrentSocketAffility());

}

void NumaSensitiveTask::BindSocket(int node_index) {

}


