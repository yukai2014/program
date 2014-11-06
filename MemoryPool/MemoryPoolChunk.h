/*
 * MemoryPoolChunk.h
 *
 *  Created on: 2014-10-29
 *      Author: imdb
 */

#ifndef MEMORYPOOLCHUNK_H_
#define MEMORYPOOLCHUNK_H_

#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#include "../Log.h"
#include "common.h"

class MemoryPoolChunk {
public:
	virtual ~MemoryPoolChunk() {
		free(first_);
	}
	virtual void* Allocate(size_t size) = 0;
	virtual bool Init() = 0;
	bool CheckSpace(size_t size);
	inline void Reset() {
		last_ = first_;
	}
protected:
	char* first_;
	char* last_;
	char* end_;
};

class MemoryPoolSmallChunk: public MemoryPoolChunk {
public:
	MemoryPoolSmallChunk(size_t size = DEFAULT_CHUNK_SIZE):chunk_size_(size){};
	void* Allocate(size_t size);
//	bool CheckSpace(size_t size);
	bool Init();
	inline MemoryPoolSmallChunk* GetNext() {
		return next_;
	}
	inline void AssignNext(MemoryPoolSmallChunk* chunk) {
		next_ = chunk;
	}
private:
	MemoryPoolSmallChunk* next_;
	size_t chunk_size_;
};

class MemoryPoolLargeChunk: public MemoryPoolChunk {
public:
	MemoryPoolLargeChunk(size_t size):chunk_size_(size) {}
	void* Allocate(size_t size);
//	bool CheckSpace(size_t size);
	bool Init();
	inline MemoryPoolLargeChunk* GetNext() {
		return next_;
	}
	inline void AssignNext(MemoryPoolLargeChunk* chunk) {
		next_ = chunk;
	}
private:
	MemoryPoolLargeChunk* next_;
	size_t chunk_size_;
};

#endif /* MEMORYPOOLCHUNK_H_ */
