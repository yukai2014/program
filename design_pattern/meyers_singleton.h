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
 * meyers_singleton.h
 *
 *  Created on: Aug 31, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */

#ifndef program_DESIGN_PATTERN_MEYERS_SINGLETON_H_
#define program_DESIGN_PATTERN_MEYERS_SINGLETON_H_

#include <iostream>

/***
 * @brief
 */
class Singleton {
 private:
  /**
   * @brief Singleton Constructor.
   * @param
   * @details  here is an example (additional)
   */
  explicit Singleton(int k) : i(k) {}
  Singleton(Singleton& s);
  void operator=(Singleton& s);    // NOLINT

 public:
  ~Singleton() {}
  static Singleton& instance() {
    static Singleton s(12);
    return s;
  }
  int get_i() {
    return i;
  }
  void set_i(int k) {
    i = k;
  }

 private:
  int i;
};


#endif /* program_DESIGN_PATTERN_MEYERS_SINGLETON_H_ */
