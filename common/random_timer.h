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
 * random_timer.h
 *
 *  Created on: Sep 3, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */

#ifndef program_COMMON_RANDOM_TIMER_H_
#define program_COMMON_RANDOM_TIMER_H_
#include <stdlib.h>

#include "./time_getter.h"
namespace yukaiprogram {

namespace common {

/***
 * A timer in random time with specified max value
 */
class RandomTimer {
 public:
  /**
   * @brief RandomTimer Constructor.
   * @param max_time(int) set the max value of random delay
   */
  explicit RandomTimer(int max_time) {
    create_time_ = TimeGetter::GetCurrentMs();
    unsigned int seed = create_time_;
    delay_ = rand_r(&seed) % max_time;
  }
  /**
   * @brief RandomTimer Destructor.
   */
  ~RandomTimer() {}


 public:
  bool End() {
    return TimeGetter::GetElapsedTime(create_time_) >= delay_;
  }

 private:
  double create_time_;
  double delay_;
};


}  // namespace common

}  // namespace yukaiprogram




#endif /* program_COMMON_RANDOM_TIMER_H_ */
