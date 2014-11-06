/*
 * MemoryPoolChunk.cpp
 *
 *  Created on: 2014-10-29
 *      Author: imdb
 */

#include "MemoryPoolChunk.h"

bool MemoryPoolChunk::CheckSpace(size_t size) {
	char *temp;
	temp = ALIGN(last_, ALIGN_SIZE);
	if (end_ - temp < size) {
		DLOG("The chunk whose first_ is %p have no %d Bytes free space", first_, size);
		return false;
	}
	return true;
}

// get memory from system
bool MemoryPoolSmallChunk::Init() {
	first_ = (char*)memalign(CACHELINE_SIZE, chunk_size_ * sizeof(char));
	if (first_ == NULL) {
		ELOG("malloc fails. No memory!");
		return false;
	}
	memset(first_, 0, chunk_size_ * sizeof(char));

	last_ = first_;
	end_ = first_ + chunk_size_;
	next_ = NULL;
	LOG("init ok. first_ is %p, last_ is %p, end_ is %p, next_ is %p", first_, last_, end_, next_);
	return true;
}

void* MemoryPoolSmallChunk::Allocate(size_t size) {
	assert(size < chunk_size_);

	if (CheckSpace(size) == false) {
		ELOG("allocate fails.");
		return NULL;
	}
	char *temp = ALIGN(last_, ALIGN_SIZE);
	last_ = temp + size;
	return (void*)temp;
}

bool MemoryPoolLargeChunk::Init() {
	first_ = (char*)memalign(CACHELINE_SIZE, chunk_size_ * sizeof(char));
	if (first_ == NULL) {
		ELOG("malloc fails. No memory!");
		return false;
	}
	memset(first_, 0, sizeof(char) * chunk_size_);

	last_ = first_;
	end_ = first_ + chunk_size_;
	next_ = NULL;
	LOG("init ok. first_ is %p, last_ is %p, end_ is %p, next_ is %p", first_, last_, end_, next_);
	return true;
}

void* MemoryPoolLargeChunk::Allocate(size_t size) {
	if (size > chunk_size_) {
		ELOG("size is too big than chunk size");
		return NULL;
	}
	char *r = last_;
	last_ += size;
	return (void*)r;
}


