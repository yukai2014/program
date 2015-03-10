/*
 * common.h
 *
 *  Created on: 2014-10-29
 *      Author: imdb
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <stdint.h>

#define ALIGN(p, a) \
	(char *) (((uintptr_t) (p) + ((uintptr_t) a - 1)) & ~((uintptr_t) a - 1))

#define PAGESIZE 4096	// Byte, recommend by nginx

#define ALIGN_SIZE 4	// Byte, recommend by nginx

#define CACHELINE_SIZE 64	// Byte

#define DEFAULT_CHUNK_SIZE 2*1024*1024 // Byte

#define THREAD_SAFE

//#define SPIN_LOCK

//#define MY_SPIN_LOCK


#endif /* COMMON_H_ */
