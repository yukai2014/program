bin_PROGRAMS = threadpoolyk 
#threadpoolzl

threadpoolyk_SOURCES = 		logs.h \
	SimpleThreadPoolTest.cpp \
	thread_pool.cpp 		thread_pool.h \
	task.h				task.cpp \
	cpu_scheduler.h
	
threadpoolyk_CPPFLAGS=-fPIC -g -O0 -Dyk
	
threadpoolyk_LDFLAGS = -lpthread -lc -lm -lrt -lxs -lnuma

threadpoolyk_LDADD = ../common/libcommon.a

#threadpoolzl_SOURCES = 		Logs.h \
	SimpleThreadPoolTest.cpp \
	ThreadPool.cpp 		ThreadPool.h \
	Thread_Pool.cpp 		Thread_Pool.h \
	Task.h				Task.cpp \
	CpuScheduler.h
	
#threadpoolzl_CPPFLAGS= -g -O0  -Dzl -fPIC
	
#threadpoolzl_LDFLAGS = -lpthread -lc -lm -lrt -lxs -lnuma