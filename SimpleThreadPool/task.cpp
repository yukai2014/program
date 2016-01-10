/*
 * Task.cpp
 *
 *  Created on: May 9, 2015
 *      Author: yukai
 */

#include "./task.h"

#include <iostream>
#include <vector>
// #define SPECIFY_CPU

/*
 *  get old binded CPU and bind new CPU in specify socket,
 *  run function f,
 *  bind to old CPU again
 */
void NumaSensitiveTask::Run() {
  vector<int> old_cpu = GetCurrentCpuAffinity();
// Logs::log("Before bind socket:\tCurrent cpu is: %d\tCurrent node is: %d\n",
// getCurrentCpuAffility(), getCurrentSocketAffility());
#ifdef SPECIFY_CPU
  int cpu_index = GetNextCPUinSocket(node_index_);
  SetCpuAffinity(cpu_index);
#else
  struct bitmask* bm = numa_allocate_nodemask();
  numa_bitmask_clearall(bm);
  for (int i = 0; i < node_index_.size(); ++i)
    numa_bitmask_setbit(bm, node_index_[i]);

  // bind to the first CPU in this numa node, same as numa_run_on_node()
  numa_run_on_node_mask_all(bm);
// Logs::log("After numa_run_on_node_mask_all");
#endif
  Task::Run();

  // restore old binding
  SetCpuAffinity(old_cpu);
  // Logs::log("After restoring:\tCurrent cpu is: %d\tCurrent node is: %d\n",
  // getCurrentCpuAffility(), getCurrentSocketAffility());
}

void NumaSensitiveTask::BindSocket(int node_index) {}

void CpuSensitiveTask::Run() {
  vector<int> old_cpu = GetCurrentCpuAffinity();
  std::cout << "before setting, Current cpu is: ";
  for (auto it : GetCurrentCpuAffinity()) std::cout << it << "\t";
  std::cout << std::endl;
  if (false == SetCpuAffinity(cpu_index_)) {
    Logs::elog("failed to set affinity with CPU: ");
    for (int i = 0; i < cpu_index_.size(); ++i)
      Logs::elog("%d ", cpu_index_[i]);
    Logs::elog("\n");
  }
  std::cout << "after setting, Current cpu is: ";
  for (auto it : GetCurrentCpuAffinity()) std::cout << it << "\t";
  std::cout << std::endl;
  Task::Run();

  // restore old binding
  SetCpuAffinity(old_cpu);
  std::cout << "after restoring, Current cpu is: ";
  for (auto it : GetCurrentCpuAffinity()) std::cout << it << "\t";
  std::cout << std::endl;
}
