/*
 * Task.h
 *
 *  Created on: May 9, 2015
 *      Author: yukai
 */

#ifndef SIMPLETHREADPOOL_TASK_H_
#define SIMPLETHREADPOOL_TASK_H_

#include <vector>
#include "./cpu_scheduler.h"
#include "./logs.h"

class Task {
 public:
  typedef void *(*void_function)(void *);

 public:
  // Task() = default;
  Task(void_function f, void *a) : func_(f), arg_(a) {}
  virtual ~Task() {}
  virtual void Run() { (*func_)(arg_); }

  static inline void DestroyTask(Task *task) { delete task; }

 protected:
  void_function func_;  // pointer to function
  void *arg_;           // the parameter of function
};

class NumaSensitiveTask : public Task {
 public:
  NumaSensitiveTask(void_function f, void *a, int node_index) : Task(f, a) {
    if (node_index < 0 || node_index >= GetNumberOfSockets()) {
      Logs::elog("Socket index %d is over range, expect 0 to %d ", node_index,
                 GetNumberOfSockets() - 1);
      assert(false);
    }
    node_index_.push_back(node_index);
  }
  NumaSensitiveTask(void_function f, void *a, vector<int> nodes)
      : Task(f, a), node_index_(nodes) {
    for (int i = 0; i < node_index_.size(); ++i) {
      if (node_index_[i] < 0 || node_index_[i] >= GetNumberOfSockets()) {
        Logs::elog("Socket index %d is over range, expect 0 to %d ",
                   node_index_[i], GetNumberOfSockets() - 1);
        assert(false);
      }
    }
  }
  virtual ~NumaSensitiveTask() throw() {}

  virtual void Run();
  void BindSocket(int node_index);

 private:
  vector<int> node_index_;
};

class CpuSensitiveTask : public Task {
 public:
  CpuSensitiveTask(void_function f, void *a, vector<int> cpu_index)
      : Task(f, a), cpu_index_(cpu_index) {
    for (int i = 0; i < cpu_index_.size(); ++i) {
      if (cpu_index_[i] < 0 || cpu_index_[i] >= GetNumberOfCpus()) {
        Logs::elog("CPU index %d is over range, expect 0 to %d ", cpu_index_[i],
                   GetNumberOfCpus() - 1);
        assert(false);
      }
    }
  }
  CpuSensitiveTask(void_function f, void *a, int cpu_index) : Task(f, a) {
    if (cpu_index < 0 || cpu_index >= GetNumberOfCpus()) {
      Logs::elog("CPU index %d is over range, expect 0 to %d ", cpu_index,
                 GetNumberOfCpus() - 1);
      assert(false);
    }
    cpu_index_.push_back(cpu_index);
  }
  virtual void Run();

 private:
  vector<int> cpu_index_;
};

class DestroyTask : public Task {
 public:
  DestroyTask() : Task(NULL, NULL) {}
  ~DestroyTask() throw() {}
  void Run() {
    Logs::log("pthread_exit...\n");
    pthread_exit(NULL);
  }
};

#endif /* SIMPLETHREADPOOL_TASK_H_ */
