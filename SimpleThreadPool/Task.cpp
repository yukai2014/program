/*
 * Task.cpp
 *
 *  Created on: May 9, 2015
 *      Author: yukai
 */

#include "Task.h"

#define SPECIFY_CPU

/*
 *  get old binded CPU and bind new CPU in specify socket,
 *  run function f,
 *  bind to old CPU again
 */
void NumaSensitiveTask::Run() {
  int old_cpu = getCurrentCpuAffinity();
//	Logs::log("Before bind socket:\tCurrent cpu is: %d\tCurrent node is:
//%d\n", getCurrentCpuAffility(), getCurrentSocketAffility());
#ifdef SPECIFY_CPU
  int cpu_index = GetNextCPUinSocket(node_index_);
  setCpuAffinity(cpu_index);
#else
  struct bitmask* bm = numa_allocate_nodemask();
  numa_bitmask_clearall(bm);
  numa_bitmask_setbit(bm, node_index_);
  // numa_bind(bm);
  //// bind to the first CPU in this numa node
  // numa_run_on_node(node_index_);
  // Logs::log("After numa_run_on_ndoe");

  // bind to the first CPU in this numa node, same as numa_run_on_node()
  numa_run_on_node_mask_all(bm);
//	Logs::log("After numa_run_on_node_mask_all");
#endif
  Task::Run();

  // restore old binding
  setCpuAffinity(old_cpu);
  // Logs::log("After restor:\tCurrent cpu is: %d\tCurrent node is: %d\n",
  // getCurrentCpuAffility(), getCurrentSocketAffility());
}

void NumaSensitiveTask::BindSocket(int node_index) {}

void CpuSensitiveTask::Run() {
  int old_cpu = getCurrentCpuAffinity();
  int expect_cpu_index = cpu_index_ % getNumberOfCpus();
  if (false == setCpuAffinity(expect_cpu_index)) {
    Logs::elog("failed to set CPU %d affinity", expect_cpu_index);
  }

  Task::Run();

  // restore old binding
  setCpuAffinity(old_cpu);
}
