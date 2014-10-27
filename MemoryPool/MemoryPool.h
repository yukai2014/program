/*
 * MemoryPool.h
 *
 *  Created on: 2014-10-21
 *      Author: imdb
 */

#ifndef MEMORYPOOL_H_
#define MEMORYPOOL_H_

#include <iostream>
#include <malloc.h>

#include "../Log.h"
using namespace std;

class MemoryPool
{
public:
	static MemoryPool* GetInstance();

	MemoryPool(){}

	void CreateMemoryPool();

	void* k_malloc(unsigned size);

	void k_free(void *ptr);

	void DestroyMemoryPool();

private:
	static MemoryPool* instance_;
};

#endif /* MEMORYPOOL_H_ */
