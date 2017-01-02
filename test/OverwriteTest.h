/*
 * Copyright [2012-2015] YuKai
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
 * OverwriteTest.h
 *
 *  Created on: Mar 22, 2016
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#ifndef test_OVERWRITETEST_H_
#define test_OVERWRITETEST_H_
#include <iostream>
using std::cout;
using std::endl;

class OwParent {
 public:
  void f() { std::cout << "Parent::f()" << endl; }
};

class OwChild : public OwParent {
 public:
  using OwParent::f;
  void f(int i) {
    cout << "Child::f(int)" << endl;
    //    this->f();
  }
};

void TestOverwrite() {
  OwChild child;
  child.f(1);
}

#endif /* test_OVERWRITETEST_H_ */
