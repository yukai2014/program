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
 * TCMallocTest.cpp
 *
 *  Created on: Aug 22, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 * 
 * Description:
 *
 */

#include <boost/serialization/map.hpp>
#include <pthread.h>
#include <sys/time.h>
#include <gperftools/heap-checker.h>
#include <cstring>
#include <iostream>
#include <thread>   // NOLINT
using std::cout;
using std::endl;
using std::thread;
// using std::mutex;

void MallocMemory(pthread_mutex_t* lock) {
  unsigned int seed = (unsigned) time(NULL);
  int length = 0;
  timeval start;
  timeval end;
  {
//    HeapLeakChecker::Disabler disabler;
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10000; ++i) {
      length = rand_r(&seed) % (32 * 1024);
      char* temp = static_cast<char*>(malloc(length));
    }
    gettimeofday(&end, NULL);
  }

//  char *t1 = static_cast<char*>(malloc(20*1024*1024));

  pthread_mutex_lock(lock);
  cout
      << " Mallocing 10000 times uses "
      << (end.tv_usec - start.tv_usec) / 1000.0
          + (end.tv_sec - start.tv_sec) * 1000.0
      << " ms" << endl;
  pthread_mutex_unlock(lock);
}

void Foo() {
  char *t = static_cast<char*>(malloc(12*1024*1024));
}

int main12() {
  char *t = static_cast<char*>(malloc(4*1024*1024));
  strcpy(t, "we");
  free(t);
//  snprintf();
  char *t1 = static_cast<char*>(malloc(20*1024*1024));

// don't recommend this usage, because it may report false leaks
//  HeapLeakChecker heap_checker("test_foo");
  {
    Foo();
  }
//  if (true) assert(NULL == "heap memory leak");

  pthread_mutex_t lock;
  pthread_mutex_init(&lock, NULL);
  thread td1(&MallocMemory, &lock);
  thread td2(&MallocMemory, &lock);
  thread td3(&MallocMemory, &lock);
  thread td4(&MallocMemory, &lock);
  td1.join();
  td2.join();
  td3.join();
  td4.join();
//  MallocExtension::instance()->GetNumericProperty(
//      "generic.current_allocated_bytes", &value);
  return 0;
}

