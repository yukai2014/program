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
#include "CpuScheduler.h"

#define yk
#ifdef yk
//#include "SimpleThreadPool/ThreadPool.h"
#include "ThreadPool.h"
#endif



using namespace std;

const int thread_count = 6;

void func(void *a){
	int num = *(int *)a;
//	while (num--);
	cout<<num<<endl;
}

void ShowSocketAndCpu(void *no_means) {
	cout<<"Current cpu is: "<<getCurrentCpuAffility()<<"\t"
			<<"Current node is: "<<getCurrentSocketAffility()<<endl;
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
	if (tp->ThreadPoolInit(thread_count) == 0) {
		cout<<"init failed"<<endl;
	}
	while (task_count--){
		tp->AddTask(&func, &num);
//		tp->Add
	}
	ThreadPool::DestroyPool(tp);

//	usleep(3000000);
	cout<<"==========================="<<endl;
	if (tp->ThreadPoolInit(thread_count) == 0) {
		cout<<"init failed"<<endl;
	}
	task_count = 10;
	int node_num = getNumberOfSockets();
	int node = 0;
	for(int i = 0; i < task_count; ++i) {
		tp->AddTastInSocket(ShowSocketAndCpu, NULL, (node++)%node_num);
	}
	ThreadPool::DestroyPool(tp);
#endif

	timeval finish_time;
	gettimeofday(&finish_time, NULL);
	cout<<" use "<<(double)(finish_time.tv_usec - start_time.tv_usec)/1000+(finish_time.tv_sec - start_time.tv_sec)*1000<<" ms"<<endl;


//	while(1){
//		sleep(1);
//	}
	return 0;
}
