/*
 * FixMemoryPool.cpp
 *
 *  Created on: 2014-10-21
 *      Author: imdb
 */
#include "MemoryPool.h"

MemoryPool* MemoryPool::instance_ = NULL;

void Destroy(int signal) {
	if (signal == SIGINT) {
		MemoryPool* mp = MemoryPool::GetInstance();
		mp->DestroyMemoryPool();
//		LOG("destroy memory pool successfully~");
		exit(1);
	}
}

MemoryPool* MemoryPool::GetInstance() {
	if (instance_ == NULL) {
		LOG("new Memory Pool");
		return instance_ = new MemoryPool();
	}
	else {
		return instance_;
	}
}

MemoryPool::MemoryPool() {
	signal(SIGINT, Destroy);
	destroy_time = 0;
}

void MemoryPool::CreateMemoryPool(size_t chunk_size){
	chunk_size_ = chunk_size;
	max_alloc_size_ = chunk_size;

	small_ = new MemoryPoolSmallChunk(chunk_size_);
	if (small_->Init()) {
		LOG("create memory pool successfully.");
	}
	else {
		ELOG("create memory pool fails.");
	}
	large_ = NULL;
	max_alloc_size_ = max_alloc_size_ > PAGESIZE - 1? PAGESIZE - 1: max_alloc_size_;
}

void* MemoryPool::KMalloc(size_t size) {
	if (size > max_alloc_size_)
		return KMallocLarge(size);

	MemoryPoolSmallChunk* chunk = small_;
	while(chunk) {
		if (chunk->CheckSpace(size)) {
			return chunk->Allocate(size);
		}

		// point to next Chunk
		if (chunk->GetNext() != NULL) {
			chunk = chunk->GetNext();
		}
		else {	// need to add new Chunk and init
			MemoryPoolSmallChunk *new_chunk = new MemoryPoolSmallChunk(chunk_size_);
			if (new_chunk->Init()) {
				chunk->AssignNext(new_chunk);
				return new_chunk->Allocate(size);
			}
			else if (new_chunk->Init()) {	// try again
				chunk->AssignNext(new_chunk);
				return new_chunk->Allocate(size);
			}
			else{
				ELOG("new chunk init fails. no memory!");
				return NULL;
			}
		}
	}
	return NULL;
	// now chunk point to NULL

}

// allocate large memory
void* MemoryPool::KMallocLarge(size_t size) {
	MemoryPoolLargeChunk* chunk = large_;
	MemoryPoolLargeChunk* new_chunk;
	int chunk_num = 0;

	while (!(chunk && chunk->CheckSpace(size))) {

		// if no chunk or no suitable chunk found after three time, create new chunk
		if (!chunk || chunk_num >= 3) {
			chunk = new MemoryPoolLargeChunk(size);
			if (chunk->Init()) {
				if (large_ != NULL) {
					chunk->AssignNext(large_->GetNext());
					large_->AssignNext(chunk);
				}
				else {
					large_ = chunk;
					large_->AssignNext(NULL);
				}
			}
			else {
				return NULL;
			}
			break;
		}

		chunk = chunk->GetNext();
		++chunk_num;
	}

	return chunk->Allocate(size);
}

void* MemoryPool::KCalloc(size_t size) {
	void *res = NULL;
	if ((res = KMalloc(size)) != NULL)
		memset(res, 0, size);

	return res;
}


void MemoryPool::ResetMemoryPool() {
	MemoryPoolSmallChunk* small_chunk = small_;
	MemoryPoolLargeChunk* large_chunk = large_;
	MemoryPoolLargeChunk* temp;

//	struct timeval s, e;
//	gettimeofday(&s, NULL);
	while(small_chunk) {
		small_chunk->Reset();
		small_chunk = small_chunk->GetNext();
	}
//	gettimeofday(&e, NULL);
//	cout<<" reset small spend "<<(double)(e.tv_usec - s.tv_usec)/1000+(e.tv_sec - s.tv_sec) * 1000<<"ms"<<endl;

	// keep first three chunk, free other
	int large_num = 0;
	while (large_chunk) {
		if (large_num >= 3) {
			temp = large_chunk;
			large_chunk = large_chunk->GetNext();
			delete temp;
		}
		else {
			large_chunk->Reset();
			large_chunk = large_chunk->GetNext();
		}
		++large_num;
	}
	LOG("free %d large chunk.reset memory pool successfully.", large_num-3);
}

void MemoryPool::DestroyMemoryPool() {
//	printf("\n");
	DLOG("it is %d time to destroy", ++destroy_time);
	MemoryPoolLargeChunk* large = large_;
	MemoryPoolSmallChunk* small = small_;
	DLOG("large is %p, small is %p", large, small);

	MemoryPoolLargeChunk* large_temp;
	MemoryPoolSmallChunk* small_temp;

	int small_count = 0;
	int large_count = 0;

//	struct timeval start, end;
//	gettimeofday(&start, NULL);

	while (large) {
		large_temp = large;
		large = large->GetNext();
		delete large_temp;
		large_temp = NULL;
		++large_count;
	}
	large_ = NULL;
//
//	gettimeofday(&end, NULL);
//	cout<<"free large use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec)<<" ms"<<endl;

//	gettimeofday(&start, NULL);
	while (small) {
		small_temp = small;
		small = small->GetNext();
		delete small_temp;
		small_temp = NULL;
		++small_count;
	}
	small_ = NULL;
//	gettimeofday(&end, NULL);
//	cout<<"free small use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec)<<" ms"<<endl;

	LOG("Destroy memory pool successfully. %d small chunk are freed, %d large chunk are freed.", small_count, large_count);
}

