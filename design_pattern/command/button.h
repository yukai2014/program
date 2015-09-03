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
 * button.h
 *
 *  Created on: Sep 1, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */

#ifndef program_DESIGN_PATTERN_COMMAND_BUTTON_H_
#define program_DESIGN_PATTERN_COMMAND_BUTTON_H_

#include <iostream>
#include <string>
#include "../common/random_timer.h"


namespace yukaiprogram {

namespace designpattern {

using std::string;
using common::RandomTimer;

/***
 * @brief
 */
class Button {
//  using common::RandomTimer ;     // error. Using directive can't be in class scope

 public:
  /**
   * @brief Button Constructor.
   * @param
   * @details  here is an example (additional)
   */
  explicit Button(string name)
      : id_(s_id++),
        name_(name),
        pressed_(false),
        handled_(false),
        r_timer_(10) {
  }
  /**
   * @brief Button Destructor.
   */
  ~Button() {}

  bool isHandled() const {
    return handled_;
  }

  void setHandled(bool handled) {
    this->handled_ = handled;
  }

  bool isPressed() {
    if (r_timer_.End())
      pressed_ = true;
    return pressed_;
  }

  void setPressed(bool pressed) {
    this->pressed_ = pressed;
  }

  int getId() const {
    return id_;
  }

  void setId(int id) {
    id_ = id;
  }

  const string& getName() const {
    return name_;
  }

  void setName(const string& name) {
    name_ = name;
  }

 private:
  int id_;
  string name_;
  bool pressed_;
  bool handled_;

  RandomTimer r_timer_;

  static int s_id;
};


}  // namespace designpattern

}  // namespace yukaiprogram


#endif /* program_DESIGN_PATTERN_COMMAND_BUTTON_H_ */
