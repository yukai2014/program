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
 * MemoryLayoutOfC.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: yukai
 *		 Email: yukai2014@gmail.com
 *
 * Description:
 *
 */

#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int global_uninit;
int global_initialize = 0;
const int const_global_int = 1;
const char const_global_char = 'a';
const char *const_global_string1 = "ab";
const string const_global_string2 = "abc";
string global_string = "abc";

int main123533() {  //  http://blog.csdn.net/sgbfblog/article/details/7772153
                    //  图很好，也有解释

  puts("=====================================");
  {             //无论初始化了没有，都是存储在栈。
    int a;      // 栈
    int b = 2;  // 栈
    printf("a:            %p\n", &a);
    printf("b:            %p\n", &b);
    int s[5];         // 栈
    int ss[5] = {0};  // 栈
    printf("s:            %p\n", s);
    printf("ss:           %p\n", ss);
    char init[] = "abc";
    printf("init:         %p\n", init);
  }

  {  // global, global_init, uninitialized, initialized都是存储在全局/静态存储区
    static int uninitialized;
    static int initialized = 0;

    //            static char *uninit;        // is NULL
    static char static_init[] = "abc";
    static char *static_char_constant = "abc";
    static char static_char = 'a';
    //            printf("uninit:     %p\n", uninit);

    printf("global int:       %p\n", &global_uninit);
    printf("global_init int:  %p\n", &global_initialize);
    printf("static uninitialized int: %p\n", &uninitialized);
    printf("static initialized int:   %p\n", &initialized);

    printf("static_init char[]:           %p\n", static_init);
    printf("static_init char constant:    %p\n", static_char_constant);
    printf("static_init char:             %p\n", &static_char);
  }
  {
    //            static
    char *const_init = "abc";  // 文字常量存储区
    printf("const_char_constant:      %p\n", const_init);
    printf("abcde:            %p\n", &"abcde");
    printf("def:          %p\n", &"def");
    // 接下来是查看这一片内存存放的内容
    //      "abc";
    //      "def";
    //      for (long i = (long)&"abc"-10; i < (long)&"def"+3; i++) {
    //        char *t = (char*)i;
    //        printf("%ld:%p:%c\n", i, t, *t);
    //      }
  }
  {
    // const
    const int const_int = 1;                               // stack
    const char const_char = 'a';                           // stack
    const char *const_string1 = "ab";                      // 文字常量区
    const string const_string2 = "abc";                    // stack
    printf("const int:            %p\n", &const_int);      // stack
    printf("const char:           %p\n", &const_char);     // stack
    printf("const string:         %p\n", &const_string2);  // stack

    printf("const gloabl int:     %p\n", &const_global_int);  // 文字常量区
    printf("const gloabl char:    %p\n", &const_global_char);  // 文字常量区

    printf("const char constant:  %p\n", const_string1);  // 文字常量区
    printf("const gloabl char constant:   %p\n",
           const_global_string1);  // 文字常量区

    printf("const gloabl string:  %p\n", &const_global_string2);
    printf("gloabl string:  %p\n", &global_string);
  }
  {
    // malloc
    // 分配哪里的内存,很大和很小的分别为两个地方的内存，默认小余128kB内存使用brk（）在堆中分配，大内存使用mmap（）在映射区分配内存
    int *p1 = (int *)malloc(100 * sizeof(int));  // 堆
    int *p2 =
        (int *)malloc(1000000 * sizeof(int));  // 映射区  ---->准确说是虚拟内存
    printf("p1:           %p\n", p1);
    printf("p2:           %p\n", p2);
    free(p1);
    free(p2);

    // new is same as malloc
    int *new1 = new int[5];
    int *new2 = new int[10000000];
    printf("new1:         %p\n", new1);
    printf("new2:         %p\n", new2);
    delete (new1);
    delete new2;
  }
  /*
  =====================================
  a:            0x7fff631d01a8
  b:            0x7fff631d01a4
  s:            0x7fff631d0190
  ss:           0x7fff631d0170
  init:         0x7fff631d0160
  global int:       0x6020d0
  global_init int:  0x6020d4
  static uninitialized int: 0x6020e8
  static initialized int:   0x6020ec
  static_init char[]:           0x6020b0
  static_init char constant:    0x401142
  static_init char:             0x6020c0
  const_char_constant:      0x401142
  abcde:            0x401164
  def:          0x401180
  const int:            0x7fff631d015c
  const char:           0x7fff631d015b
  const string:         0x7fff631d0150
  const gloabl int:     0x4012bc
  const gloabl char:    0x4012c0
  const char constant:  0x400fe1
  const gloabl char constant:   0x400fe1
  const gloabl string:  0x6020e0
  gloabl string:  0x6020d8
  p1:           0xe2d070
  p2:           0x7fa3eeb60010
  new1:         0xe2d040
  new2:         0x7fa3ec90b010
  */
  return 0;
}
