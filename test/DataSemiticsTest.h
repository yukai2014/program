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
 * DataSemiticsTest.h
 *
 *  Created on: May 19, 2016
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#ifndef test_DATASEMITICSTEST_H_
#define test_DATASEMITICSTEST_H_
#include <iostream>
using namespace std;

class EmptyClass {};

class DerivedClass : public EmptyClass {};

class VirtualDerivedClassX : public virtual EmptyClass {};
class VirtualDerivedClassY : public virtual EmptyClass {};

class DDerived : public VirtualDerivedClassY, public VirtualDerivedClassX {};

void TestDataSemitics() {
  cout << "empty class size is:" << sizeof(EmptyClass) << endl;
  cout << "derived class of empty class size is:" << sizeof(DerivedClass)
       << endl;
  cout << "virtual derived class of empty class  empty class sizeof is:"
       << sizeof(VirtualDerivedClassX) << endl;
  cout << "grand virtual class  size is:" << sizeof(DDerived) << endl;
}

#endif /* test_DATASEMITICSTEST_H_ */
