/*
 * MemoryPoolChunk.cpp
 *
 *  Created on: 2014-10-29
 *      Author: imdb
 */

#include "MemoryPoolChunk.h"
extern int lock_time;

#ifdef MY_SPIN_LOCK
int MemoryPoolChunk::is_lock = 0;
#endif

bool MemoryPoolChunk::CheckSpace(size_t size) {
	/*
	char *temp;
	temp = ALIGN(last_, ALIGN_SIZE);
	if (end_ - temp < size) {
//		DLOG("The chunk whose first_ is %p have no %d Bytes free space", first_, size);
		return false;
	}
	 */
#if defined(THREAD_SAFE)
	pthread_mutex_lock(&lock_);
#elif defined(SPIN_LOCK)
	spin_lock(&lock_);
#elif defined(MY_SPIN_LOCK)
	while(MemoryPoolChunk::is_lock);
	__sync_fetch_and_add(&MemoryPoolChunk::is_lock, 1);
#endif
	++lock_time;

	if (free_length_ > size + ALIGN_SIZE) {	// apply ALIGN_SIZE size free memory for aligning
		free_length_ -= size;
#if defined(THREAD_SAFE)
		pthread_mutex_unlock(&lock_);
#elif defined(SPIN_LOCK)
		spin_unlock(&lock_);
#elif defined(MY_SPIN_LOCK)
		__sync_fetch_and_sub(&MemoryPoolChunk::is_lock, 1);
#endif
		return true;
	}
	else {
#if defined(THREAD_SAFE)
		pthread_mutex_unlock(&lock_);
#elif defined(SPIN_LOCK)
		spin_unlock(&lock_);
#elif defined(MY_SPIN_LOCK)
		__sync_fetch_and_sub(&MemoryPoolChunk::is_lock, 1);
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
#if defined(THREAD_SAFE)
	pthread_mutex_init(&lock_, NULL);
#elif defined(SPIN_LOCK)
	spin_lock_init(&lock_);
#elif defined(MY_SPIN_LOCK)
	MemoryPoolChunk::is_lock = 0;
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
#if defined(THREAD_SAFE)
	pthread_mutex_lock(&lock_);
#elif defined(SPIN_LOCK)
	spin_lock(&lock_);
#elif defined(MY_SPIN_LOCK)
	while(MemoryPoolChunk::is_lock);
	__sync_fetch_and_add(&MemoryPoolChunk::is_lock, 1);
#endif
	++lock_time;
	//	int inc = ALIGN(size, ALIGN_SIZE);
	//	__sync_add_and_fetch(last_, inc);

	char *temp = last_;
	last_ = ALIGN(temp + size, ALIGN_SIZE);
	free_length_ = end_ - last_;
#if defined(THREAD_SAFE)
	pthread_mutex_unlock(&lock_);
#elif defined(SPIN_LOCK)
	spin_unlock(&lock_);
#elif defined(MY_SPIN_LOCK)
	__sync_fetch_and_sub(&MemoryPoolChunk::is_lock, 1);
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
#if defined(THREAD_SAFE)
	pthread_mutex_init(&lock_, NULL);
#elif defined(SPIN_LOCK)
	spin_lock_init(&lock_);
#elif defined(MY_SPIN_LOCK)
	MemoryPoolChunk::is_lock = 0;
#endif
	LOG("init ok. first_ is %p, last_ is %p, end_ is %p, next_ is %p", first_, last_, end_, next_);
	return true;
}

void* MemoryPoolLargeChunk::Allocate(size_t size) {
	if (size > chunk_size_) {
		ELOG("size is too big than chunk size");
		return NULL;
	}

#if defined(THREAD_SAFE)
	pthread_mutex_lock(&lock_);
#elif defined(SPIN_LOCK)
	spin_lock(&lock_);
#elif defined(MY_SPIN_LOCK)
	while(MemoryPoolChunk::is_lock);
	__sync_fetch_and_add(&MemoryPoolChunk::is_lock, 1);
#endif
	char *r = last_;
	last_ += size;
	free_length_ = end_ - last_;
#if defined(THREAD_SAFE)
	pthread_mutex_unlock(&lock_);
#elif defined(SPIN_LOCK)
	spin_unlock(&lock_);
#elif defined(MY_SPIN_LOCK)
	__sync_fetch_and_sub(&is_lock, 1);
#endif
	return (void*)r;
}


