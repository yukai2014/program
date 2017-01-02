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
 * c++11_features_test.h
 *
 *  Created on: Aug 18, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#ifndef test_C__11_FEATURES_TEST_H_
#define test_C__11_FEATURES_TEST_H_

#include <cstring>
#include <iostream>
#include <exception>
#include <limits>
#include <thread>  // NOLINT
#include <future>  // NOLINT
using namespace std;
// NOLINT

/**
 * @brief transform "printf" style into "cout" output style
 * @param content to be format output
 */
void elog(const char* format, ...) {
  const int message_max_length = 1000;  // set initial message length
  static char p[message_max_length];
  memset(p, 0, message_max_length * sizeof(char));

  va_list arg;
  va_start(arg, format);
  int real_length = vsnprintf(p, message_max_length, format, arg);
  va_end(arg);

  if (real_length < message_max_length) {  // if it worked, output the message
    std::cerr << "Error:" << p << std::flush;
  } else if (real_length < 0) {  // check error code and output
    std::cerr << "vsnprintf error. " << strerror(errno) << std::endl;
  } else {  // try again with more space
    int new_message_length = real_length + 1;
    char* temp = new char[new_message_length];
    if (temp == NULL) {
      std::cerr << "new " << new_message_length << " bytes failed."
                << strerror(errno) << std::endl;
      return;
    }
    // if enough space got, do it again
    va_start(arg, format);
    real_length = vsnprintf(temp, new_message_length, format, arg);
    va_end(arg);
    std::cerr << "Error:" << temp << std::flush;
  }
}

class functor {
 public:
  int operator()(int i, int j) {
    //    cout << i << "+" << j << " = " << i + j << endl;
    elog("              i + j = %d\n", i + j);
    return i + j;
  }
};

class Temp {
 public:
  Temp() { key = 123; }
  virtual void Output1() {
    //    cout << "it is Temp::Output1, which is public" << endl;
    elog("the function is TestMultiThread%d\n", 7);
  }
  virtual void OutputWithOneParam(int i) {
    cout << "it is Temp::OutputWithOneParam. i is" << i << std::endl;
  }

 private:
  void Output2() {
    cout << "it is Temp::Output2, which is private" << std::endl;
  }
  int key;
};

class TempChild : public Temp {
 public:
  TempChild() { key_child = 12345; }

  virtual void Output1() {
    cout << "it is TempChild::Output1, which is public" << std::endl;
  }

 private:
  int key_child;
};

void ThreadProcess() { cout << "hello, i am processing" << std::endl; }

void TestMultiThread1() {
  ostream& os = std::cerr;
  thread td([&os]() {
    os << "hello" << std::endl;
    elog("nice to meet you!%s\n", "world");
  });
  td.join();
}
void TestMultiThread2() {
  thread td(functor(), 3, 5);
  td.join();
}

void TestMultiThread3() {
  Temp t;
  thread td(&Temp::OutputWithOneParam, &t, 3);
  td.join();
}

void TestMultiThread4() {
  Temp t;

  //  error: ‘void Temp::Output2()’ is private
  //  thread td(std::bind(&Temp::Output2, &t));
  //  td.join();
}

void TestMultiThread5() {
  thread td;
  cout << "td's joinable is " << td.joinable() << std::endl;
  //  td.join();    // terminate called after throwing
  // an instance of 'std::system_error'
  // what():  Invalid argument
}

void TestMultiThread6() {
  Temp t;
  thread td(std::bind(&Temp::Output1, &t));

  cout << "td's joinable is " << td.joinable() << std::endl;
  td.join();
  cout << "td's joinable is " << td.joinable() << std::endl;
}

void TestMultiThread7() {
  Temp t;
  thread td([&t]() { t.Output1(); });
  cout << "thread td's id is:" << td.get_id() << std::endl;

  td.join();
}

/**
 * @brief test bind virtual function
 * @param
 * @return
 * @details   (additional)
 */

void TestMultiThread8() {
  cout << "in 8:" << std::endl;
  Temp* t = new TempChild();
  //  thread td1(std::bind(&TempChild::Output1, t));
  //  td1.join();
  thread td2(bind(&Temp::Output1, t));  // //std::bind可以表现出多态行为
  td2.join();
}

#define ASSIGN_FUNCTION(f, i) f[i - 1] = TestMultiThread##i;

void InitFunctions(function<void()> f[100], int num) {
  for (int i = 0; i < num; ++i) {
    f[i] = NULL;
  }
}

void TestMultiThread() {
  function<void()> f[100];

  InitFunctions(f, 100);
  ASSIGN_FUNCTION(f, 1);
  ASSIGN_FUNCTION(f, 2);
  ASSIGN_FUNCTION(f, 3);
  ASSIGN_FUNCTION(f, 4);
  ASSIGN_FUNCTION(f, 5);
  ASSIGN_FUNCTION(f, 6);
  ASSIGN_FUNCTION(f, 7);
  ASSIGN_FUNCTION(f, 8);
  for (int i = 0; i < 100; ++i) {
    if (f[i] != NULL) {
      f[i]();
    }
  }
}

int Add(int i, int j) {
  cout << "this " << this_thread::get_id() << std::endl;
  if (numeric_limits<int>::max() - i < j) throw overflow_error("overflow....");
  cout << "thread id is " << this_thread::get_id() << endl;  // may be the same
  return i + j;
}

void TestFuture() {
  std::future<int> f1 = std::async(std::launch::async, Add, 2, 4);
  std::future<int> f2 =
      std::async(std::launch::async, Add, 222222222222, 44444444444);

  cout << "waiting.." << std::endl;
  try {
    cout << "f1 return " << f1.get() << std::endl;
  } catch (const overflow_error& e) {
    cerr << e.what() << std::endl;
  }
}

void TestNewFeature() {
  TestMultiThread();
  TestFuture();
}

#endif /* test_C__11_FEATURES_TEST_H_ */
