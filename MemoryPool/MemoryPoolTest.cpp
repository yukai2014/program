/*
 * MemoryPoolTest.cpp
 *
 *  Created on: 2014-10-27
 *      Author: imdb
 */

#include <iostream>
#include "MemoryPool.h"
using namespace std;

int main(){
	MemoryPool *memory_pool = MemoryPool::GetInstance();
	memory_pool = MemoryPool::GetInstance();
	memory_pool = MemoryPool::GetInstance();
	return 0;
}
