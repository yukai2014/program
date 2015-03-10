bin_PROGRAMS = memorypool

memorypool_SOURCES = MemoryPool.cpp \
	MemoryPool.h	MemoryPoolTest.cpp \
	MemoryPoolChunk.cpp MemoryPoolChunk.h \
	common.h
	
memorypool_CPPFLAGS= -g -fPIC
	
memorypool_LDFLAGS =-lc -lm -lrt -lpthread

LDADD = ../common/libcommon.a