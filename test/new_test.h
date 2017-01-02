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
 * new_test.h
 *
 *  Created on: Feb 23, 2016
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#ifndef test_NEW_TEST_H_
#define test_NEW_TEST_H_
#include <iostream>
#include <new>
using std::cout;
using std::endl;
using std::cin;

class NewTestClass {
 public:
  NewTestClass() { cout << "NewTestClass()" << endl; }

  explicit NewTestClass(int k) {
    cout << "NewTestClass(k)" << endl;
    throw std::exception();
  }

 public:
  static void* operator new(size_t size) {
    cout << "here is new (size) size = " << size << endl;
    return ::operator new(size);
  }
  static void operator delete(void* p) { cout << "here is delete (p)" << endl; }

  static void* operator new(size_t size, int i) {
    cout << "here is new (size, i)" << endl;
    return ::operator new(size);
  }
  static void operator delete(void* p, int i) {
    cout << "here is delete (p ,size, i)" << endl;
  }
};

void TestNewDelete1() {
  cout << "------------------------------------------ " << endl;

  int k = 12;
  NewTestClass* p = new NewTestClass();  // here is new (size) size = 1
                                         // NewTestClass()
  delete p;                              // here is delete (p)
  cout << "------------------------------------------ " << endl;

  NewTestClass* pk = new (k) NewTestClass();  // here is new (size, i)
                                              // NewTestClass()
  delete pk;                                  // here is delete (p)
  cout << "------------------------------------------ " << endl;

  /**
   * with try-catch, c++ will call placement delete after construction function
   * throwing exception
   */
  NewTestClass* pi = nullptr;
  try {
    pi = new (k) NewTestClass(k);  // here is new (size, i)
                                   // NewTestClass(k)
  } catch (const std::exception& e) {
    cout << "exception caught" << endl;  // here is delete (p ,size, i)
                                         // exception caught
  }
  delete pi;  // here is delete (p)
  cout << "------------------------------------------ " << endl;

  ///////////////////////  error!!  ///////////////////
  //  /**
  //   * without try-catch, std::exception is  throw, then program terminated
  //   * The expected action--calling placement delete:
  //   * operator delete(void*, int)--didn't happen
  //   */
  //  NewTestClass* pi2 = new (k) NewTestClass(k);  // here is new (size, i)
  //                                                //  NewTestClass(k)
  //  // terminate called after throwing an instance of 'std::exception'
  //  //  what():  std::exception
  //  delete pi2;
  //  cout << "------------------------------------------ " << endl;
}

class NewTestClassWithOneNew {
 public:
  NewTestClassWithOneNew() {}

 public:
  static void* operator new(size_t size, int i) {
    cout << "here is new (size, i)" << endl;
    return ::operator new(size);
  }
  static void operator delete(void* p,
                              int i) {  // called when construction function
                                        // throw an exception on memory
                                        // allocated by placement new
    cout << "here is delete (p ,size, i)" << endl;
  }
  // this member function is necessary!!
  static void operator delete(void* p) throw() { ::operator delete(p); }
};

// default operator new is cover by NewTestClassWithOneNew::operator new
void TestNewDelete2() {
  int k = 12;
  /*
  NewTestClassWithOneNew* p =
      new NewTestClassWithOneNew();  // error: no matching function for call to
                                     // ‘NewTestClassWithOneNew::operator
                                     // new(sizetype)’
  delete p;
  */
  NewTestClassWithOneNew* pi = new (k) NewTestClassWithOneNew();
  delete pi;
}

class StandardNewDeleteForms {
 public:
  static void* operator new(size_t size) throw(std::bad_alloc) {
    return ::operator new(size);
  }
  static void operator delete(void* pMemory) throw() {
    ::operator delete(pMemory);
  }
  static void* operator new(size_t size, void* location) throw() {
    return ::operator new(size, location);
  }
  static void operator delete(void* pMemory, void* location) throw() {
    ::operator delete(pMemory, location);
  }
  static void* operator new(size_t size, const std::nothrow_t& nt) throw() {
    return ::operator new(size, nt);
  }
  static void operator delete(void* p, const std::nothrow_t& nt) throw() {
    ::operator delete(p, nt);
  }
};

class DerivedNewDelete : public StandardNewDeleteForms {
 public:
  using StandardNewDeleteForms::operator new;
  using StandardNewDeleteForms::operator delete;
  static void* operator new(size_t size, int i) {
    cout << "here is new (size, i)" << endl;
    return ::operator new(size);
  }
  static void operator delete(void* p, int i) {
    cout << "here is delete (p ,size, i)" << endl;
  }
};

void TestNewDelete3() {
  int k = 12;
  DerivedNewDelete* p = new DerivedNewDelete();
  delete p;
  DerivedNewDelete* pi = new (k) DerivedNewDelete();
  delete pi;
}

void TestNewDelete() {
  cout << "======================================" << endl;
  TestNewDelete1();
  cout << "======================================" << endl;
  TestNewDelete2();
  cout << "======================================" << endl;
  TestNewDelete3();
  cout << "======================================" << endl;
}
#endif /* test_NEW_TEST_H_ */
