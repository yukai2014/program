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
 * meyers_singleton_test.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */


#include "./meyers_singleton.h"
using std::cout;
using std::endl;

int main() {
  cout << Singleton::instance().get_i() << endl;
// error! call copy constructor function, which is private
//  Singleton s = Singleton::instance();

// error!  call operator= function, which is private
//  Singleton s; s = Singleton::instance();
  Singleton& s = Singleton::instance();
  s.set_i(12345);
  cout << s.get_i() << endl;
  return 0;
}


