/*
 * Test.cpp
 *
 *  Created on: 2014-8-18
 *      Author: imdb
 *
 *
 *      how to use: command--->	g++ -lpthread -g -o test_zl ThreadPoolTest.cpp Thread_Pool.cpp Test.cpp Thread_Pool.cpp Thread_Pool.h -D zl
 *      									g++ -lpthread -g -o test_yk ThreadPoolTest.cpp Thread_Pool.cpp Test.cpp Thread_Pool.cpp Thread_Pool.h -D yk
 */

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#ifdef yk
//#include "SimpleThreadPool/ThreadPool.h"
#include "ThreadPool.h"
#endif

#ifdef zl
//#include "SimpleThreadPool/Thread_Pool.h"
#include "Thread_Pool.h"
#endif

using namespace std;

const int thread_count = 5;

void func(void *a){
	int num = *(int *)a;
	while (num--);
	cout<<"^";
}

int main()
{
	int task_count = 10;
	int num = 10000;
	timeval start_time;
	gettimeofday(&start_time, NULL);
	cout<<"start"<<endl;
#ifdef yk
	ThreadPool *tp = new ThreadPool();
	tp->Thread_Pool_init(thread_count);
	while (task_count--){
		tp->add_task(&func, &num);
	}
	ThreadPool::destroy_pool(tp);
#endif

#ifdef zl
	Thread_Pool *tp = new Thread_Pool();
	tp->Thread_Pool_init(thread_count, task_count);
	while (task_count--){
		tp->Thread_Pool_add(&func, &num);
	}
	Thread_Pool::destroy(tp);
//	while(1);
#endif
	timeval finish_time;
	gettimeofday(&finish_time, NULL);
	cout<<" use "<<(double)(finish_time.tv_usec - start_time.tv_usec)/1000+(finish_time.tv_sec - start_time.tv_sec)<<" ms"<<endl;


//	while(1){
//		sleep(1);
//	}
	return 0;
}
