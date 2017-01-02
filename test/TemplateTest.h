/*
 * Copyright 2015 yukai
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * ${file_name}
 *
 *  Created on: ${date}
 *      Author: ${user}
 *		 Email: yukai2014@gmail.com
 *
 * Description:	test for template class
 *
 */

#ifndef TEMPLATETEST_H_
#define TEMPLATETEST_H_

#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class TemplateTestClass {
 public:
  // the only right way
  void Print() {
    cout << "success!" << endl;
  }
};

#endif /* TEMPLATETEST_H_ */
