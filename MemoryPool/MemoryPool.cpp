/*
 * FixMemoryPool.cpp
 *
 *  Created on: 2014-10-21
 *      Author: imdb
 */
#include "MemoryPool.h"

static MemoryPool* MemoryPool::instance_ = NULL;

MemoryPool* MemoryPool::GetInstance() {
	if (instance_ == NULL) {
		return instance_ = new MemoryPool();
	}
	else {
		return instance_;
	}
}
