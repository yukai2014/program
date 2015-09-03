/*
 * Copyright [2012-2015] DaSE@ECNU
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * task_runner.h
 *
 *  Created on: Sep 1, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */

#ifndef program_DESIGN_PATTERN_COMMAND_TASK_RUNNER_H_
#define program_DESIGN_PATTERN_COMMAND_TASK_RUNNER_H_
#include <vector>

#include "./task.h"
using std::vector;
namespace yukaiprogram {

namespace designpattern {

/***
 * @brief
 */
class TaskRunner {
 private:
  /**
   * @brief TaskRunner Constructor.
   * @param
   * @details  here is an example (additional)
   */
  TaskRunner(){
  }
  /**
   * @brief TaskRunner Destructor.
   */
  ~TaskRunner() {
  }
  TaskRunner(const TaskRunner& r);
  TaskRunner& operator=(TaskRunner& r);

 public:
  static void Run();
  static TaskRunner& Instance() {
    return runner;
  }
  static void Add(Task* task) {
    tasks_.push_back(task);
  }

 private:
  static TaskRunner runner;
  static vector<Task*> tasks_;
};

inline void TaskRunner::Run() {
  for (auto task : tasks_) {
    task->Operate();
  }
}
}  // namespace designpattern

}  // namespace yukaiprogram
#endif /* program_DESIGN_PATTERN_COMMAND_TASK_RUNNER_H_ */
