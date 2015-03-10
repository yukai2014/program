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
#include <signal.h>

#include "MemoryPoolChunk.h"
#include "../common/Log.h"
using namespace std;

void Destroy(int signal);

class MemoryPool
{
public:
	static MemoryPool* GetInstance();

	MemoryPool();

	void CreateMemoryPool(size_t chunk_size);

	/*
	 * user must memset the memory after calling KMalloc
	 */
	void* KMalloc(size_t size);

	void* KCalloc(size_t size);

	void* KMallocLarge(size_t size);

//	void KFree(void *ptr);

	void ResetMemoryPool();

	void DestroyMemoryPool();

private:
	static MemoryPool* instance_;

	int destroy_time;

	size_t chunk_size_;

	MemoryPoolSmallChunk* small_;

	MemoryPoolLargeChunk* large_;

	size_t max_alloc_size_;

};

#endif /* MEMORYPOOL_H_ */
