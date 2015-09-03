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
 * command_test.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */

#include "./command_test.h"

#include <unistd.h>
#include <vector>
#include "./button.h"
#include "./check_button.h"
#include "./task.h"
#include "./task_runner.h"

using std::vector;
namespace yukaiprogram {
namespace designpattern {

int Button::s_id;
TaskRunner TaskRunner::runner;
vector<Task*> TaskRunner::tasks_;

void CommandTest() {
  CheckButton* b1 = new CheckButton("b1");
  usleep(1000);
  CheckButton* b2 = new CheckButton("b2");
  usleep(1000);
  CheckButton* b3 = new CheckButton("b3");

  TaskRunner::Add(b1);
  TaskRunner::Add(b2);
  TaskRunner::Add(b3);
  int times = 20;
  while (times--) {
    procedure1();
    procedure2();
    procedure3();
    usleep(500);
  }
}

void procedure1() {
  std::cout << "I am doing procedure1" << std::endl;
  TaskRunner::Run();
}

void procedure2() {
  std::cout << "I am doing procedure2" << std::endl;
  TaskRunner::Run();
}

void procedure3() {
  std::cout << "I am doing procedure3" << std::endl;
  TaskRunner::Run();
}

}  // namespace designpattern

}  // namespace yukaiprogram

