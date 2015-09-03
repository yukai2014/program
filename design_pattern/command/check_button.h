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
 * check_button.h
 *
 *  Created on: Sep 2, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */

#ifndef program_DESIGN_PATTERN_COMMAND_CHECK_BUTTON_H_
#define program_DESIGN_PATTERN_COMMAND_CHECK_BUTTON_H_
#include <string>

#include "./task.h"

namespace yukaiprogram {

namespace designpattern {

/***
 * simulate a button will be pressed randomly
 */
class CheckButton : public Task {
 public:
  /**
   * @brief CheckButton Constructor.
   * @param
   * @details  
   */
  CheckButton(string name)
      : b(name) {
  }
  /**
   * @brief CheckButton Destructor.
   */
  ~CheckButton() {
  }

 public:
  void Operate();
 private:
  Button b;
};

inline void CheckButton::Operate() {
  if (b.isPressed() && !b.isHandled()) {
    std::cout << "now handling with the pressed button(" << b.getId() << ","
              << b.getName() << ")..." << std::endl;
    b.setHandled(true);
  }
}

}  // namespace designpattern

}  // namespace yukaiprogram

#endif /* program_DESIGN_PATTERN_COMMAND_CHECK_BUTTON_H_ */
