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
 * written_examination.h
 *
 *  Created on: Mar 30, 2016
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#ifndef test_WRITTEN_EXAMINATION_H_
#define test_WRITTEN_EXAMINATION_H_

#include <iostream>
using namespace std;

class Test {
 public:
  void print() { cout << "print" << endl; }
  void print() const { cout << "const print" << endl; }
  void print() volatile { cout << "volatile print" << endl; }
  void print() const volatile { cout << "const volatile print" << endl; }
};

int WrittenTest1() {
  Test t;
  t.print();
  const Test ct;
  ct.print();
  volatile Test vt;
  vt.print();
  const volatile Test cvt;
  cvt.print();
  return 0;
}

int WrittenTest() {
  WrittenTest1();
  return 0;
}

#endif /* test_WRITTEN_EXAMINATION_H_ */
