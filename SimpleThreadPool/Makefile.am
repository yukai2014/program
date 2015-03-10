bin_PROGRAMS = threadpoolyk threadpoolzl

threadpoolyk_SOURCES = 		Logs.h \
	SimpleThreadPoolTest.cpp \
	ThreadPool.cpp 		ThreadPool.h \
	Thread_Pool.cpp 		Thread_Pool.h 
	
threadpoolyk_CPPFLAGS=-fPIC -g -Dyk
	
threadpoolyk_LDFLAGS = -lpthread

threadpoolyk_LDADD = ../common/libcommon.a

threadpoolzl_SOURCES = 		Logs.h \
	SimpleThreadPoolTest.cpp \
	ThreadPool.cpp 		ThreadPool.h \
	Thread_Pool.cpp 		Thread_Pool.h
	
threadpoolzl_CPPFLAGS= -g -Dzl -fPIC
	
threadpoolzl_LDFLAGS = -lpthread	