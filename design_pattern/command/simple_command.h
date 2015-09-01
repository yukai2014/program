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
 * simple_command.h
 *
 *  Created on: Sep 1, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */

#ifndef program_DESIGN_PATTERN_COMMAND_SIMPLE_COMMAND_H_
#define program_DESIGN_PATTERN_COMMAND_SIMPLE_COMMAND_H_

#include <iostream>

/***
 * @brief
 */
class SimpleCommand {
 public:
  /**
   * @brief SimpleCommand Constructor.
   * @param
   * @details  here is an example (additional)
   */
  SimpleCommand() {}
  /**
   * @brief SimpleCommand Destructor.
   */
  virtual ~SimpleCommand() {}

 public:
  virtual void Execute() = 0;

 private:
};

/***
 * @brief
 */
class HelloCommand:public SimpleCommand {
 public:
  /**
   * @brief HelloCommand Constructor.
   * @param
   * @details  here is an example (additional)
   */
  HelloCommand() {}
  /**
   * @brief HelloCommand Destructor.
   */
  ~HelloCommand() {}


 public:
  void Execute() {
    std::cout << "hello ";
  }
 private:
};

/***
 * @brief
 */
class WorldCommand : public SimpleCommand {
 public:
  void Execute() {
    std::cout << " world ";
  }
 private:
};

#endif /* program_DESIGN_PATTERN_COMMAND_SIMPLE_COMMAND_H_ */
