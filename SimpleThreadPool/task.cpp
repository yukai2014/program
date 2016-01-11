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
 *  get old binded CPUs and bind new CPUs in specify sockets,
 *  run function f,
 *  bind to old CPUs again
 */
void NumaSensitiveTask::Run() {
  vector<int> old_cpu = GetCurrentCpuAffinity();

  std::cout << "before setting, Current cpu is: ";
  for (auto it : old_cpu) std::cout << it << " ";
  std::cout << std::endl;
#ifdef SPECIFY_CPU
  int cpu_index = GetNextCPUinSocket(node_index_);
  SetCpuAffinity(cpu_index);
#else
  struct bitmask* bm = numa_allocate_nodemask();
  numa_bitmask_clearall(bm);
  for (int i = 0; i < node_index_.size(); ++i)
    numa_bitmask_setbit(bm, node_index_[i]);

  // bind to this NUMA nodes, ignoring CPU affinities
  numa_run_on_node_mask_all(bm);
#endif
  std::cout << "after setting, Current cpu is: ";
  for (auto it : GetCurrentCpuAffinity()) std::cout << it << " ";
  std::cout << std::endl;
  Task::Run();

  // restore old binding
  SetCpuAffinity(old_cpu);
  std::cout << "after restoring, Current cpu is: ";
  for (auto it : GetCurrentCpuAffinity()) std::cout << it << " ";
  std::cout << std::endl;
}

void NumaSensitiveTask::BindSocket(int node_index) {}

void CpuSensitiveTask::Run() {
  vector<int> old_cpu = GetCurrentCpuAffinity();
  std::cout << "before setting, Current cpu is: ";
  for (auto it : GetCurrentCpuAffinity()) std::cout << it << " ";
  std::cout << std::endl;
  if (false == SetCpuAffinity(cpu_index_)) {
    Logs::elog("failed to set affinity with CPU: ");
    for (int i = 0; i < cpu_index_.size(); ++i)
      Logs::elog("%d ", cpu_index_[i]);
    Logs::elog("\n");
  }
  std::cout << "after setting, Current cpu is: ";
  for (auto it : GetCurrentCpuAffinity()) std::cout << it << " ";
  std::cout << std::endl;
  Task::Run();

  // restore old binding
  SetCpuAffinity(old_cpu);
  std::cout << "after restoring, Current cpu is: ";
  for (auto it : GetCurrentCpuAffinity()) std::cout << it << " ";
  std::cout << std::endl;
}
