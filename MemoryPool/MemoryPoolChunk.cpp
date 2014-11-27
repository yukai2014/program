/*
 * MemoryPoolChunk.cpp
 *
 *  Created on: 2014-10-29
 *      Author: imdb
 */

#include "MemoryPoolChunk.h"

bool MemoryPoolChunk::CheckSpace(size_t size) {
/*
	char *temp;
	temp = ALIGN(last_, ALIGN_SIZE);
	if (end_ - temp < size) {
//		DLOG("The chunk whose first_ is %p have no %d Bytes free space", first_, size);
		return false;
	}
	*/
#ifdef THREAD_SAFE
	pthread_mutex_lock(&lock_);
#endif
	if (free_length_ > size + ALIGN_SIZE) {	// apply ALIGN_SIZE size free memory for aligning
		free_length_ -= size;
#ifdef THREAD_SAFE
		pthread_mutex_unlock(&lock_);
#endif
		return true;
	}
	else {
#ifdef THREAD_SAFE
		pthread_mutex_unlock(&lock_);
#endif
		return false;
	}

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
	free_length_ = chunk_size_;
#ifdef THREAD_SAFE
	pthread_mutex_init(&lock_, NULL);
#endif

	LOG("init ok. first_ is %p, last_ is %p, end_ is %p, next_ is %p", first_, last_, end_, next_);
	return true;
}

void* MemoryPoolSmallChunk::Allocate(size_t size) {
	assert(size < chunk_size_);

	/*
	if (CheckSpace(size) == false) {
		ELOG("allocate fails.");
		return NULL;
	}
	*/
#ifdef THREAD_SAFE
		pthread_mutex_lock(&lock_);
#endif
	char *temp = last_;
	last_ = ALIGN(temp + size, ALIGN_SIZE);
	free_length_ = end_ - last_;
#ifdef THREAD_SAFE
		pthread_mutex_unlock(&lock_);
#endif

	DLOG("return %p", temp);
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
	free_length_ = chunk_size_;
#ifdef THREAD_SAFE
	pthread_mutex_init(&lock_, NULL);
#endif
	LOG("init ok. first_ is %p, last_ is %p, end_ is %p, next_ is %p", first_, last_, end_, next_);
	return true;
}

void* MemoryPoolLargeChunk::Allocate(size_t size) {
	if (size > chunk_size_) {
		ELOG("size is too big than chunk size");
		return NULL;
	}

#ifdef THREAD_SAFE
		pthread_mutex_lock(&lock_);
#endif
	char *r = last_;
	last_ += size;
	free_length_ = end_ - last_;
#ifdef THREAD_SAFE
		pthread_mutex_unlock(&lock_);
#endif
	return (void*)r;
}


