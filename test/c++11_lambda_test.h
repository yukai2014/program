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
 * c++11_lambda_test.h
 *
 *  Created on: Jan 28, 2016
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#ifndef test_C__11_LAMBDA_TEST_H_
#define test_C__11_LAMBDA_TEST_H_
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_value(int i) { cout << i << endl; }

void TestLambda() {
  vector<int> large_v;
  vector<int> temp_v;
  temp_v.push_back(1);
  temp_v.push_back(1);
  temp_v.push_back(3);
  temp_v.push_back(3);
  temp_v.push_back(3);
  large_v.clear();
  for_each(temp_v.begin(), temp_v.end(), print_value);
  //  for_each(temp_v.begin(), temp_v.end(), [large_v](int i) { // error compile
  for_each(temp_v.begin(), temp_v.end(), [&large_v](int i) {
    if (i > 2) large_v.push_back(i);
  });

  cout << "=======" << endl;
  for_each(large_v.begin(), large_v.end(), [](int i) { cout << i << endl; });
}

#endif /* test_C__11_LAMBDA_TEST_H_ */
