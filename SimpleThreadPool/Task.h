/*
 * Task.h
 *
 *  Created on: May 9, 2015
 *      Author: yukai
 */

#ifndef SIMPLETHREADPOOL_TASK_H_
#define SIMPLETHREADPOOL_TASK_H_

#include "CpuScheduler.h"
#include "Logs.h"
typedef void (*void_function)(void *);
const int MAX_CPU_NUM = 1000;

class Task{
public:
//	Task() = default;
//	Task(void_function f, void *a, bool e):func_(f),arg_(a),end_(e){}
	Task(void_function f, void *a):func_(f),arg_(a){}
	virtual ~Task(){}
	virtual void Run() {
		(*func_)(arg_);
	}

	static void DestroyTask(Task *task){
		// todo:the arg has no specified type
		//			delete task->arg;

		delete task;
	};

//	bool end() {return end_; }

protected:
	void_function func_;	// pointer to function
	void *arg_;						// the parameter of function
//	bool end_;						// whether exit thread
};

class NumaSensitiveTask: public Task {
public:
//	NumaSensitiveTask(){};
//	NumaSensitiveTask(void_function f, void *a, bool e, int node_index):Task(f, a, e), node_index_(node_index){}
	NumaSensitiveTask(void_function f, void *a, int node_index):
		Task(f, a), node_index_(node_index){}
	virtual ~NumaSensitiveTask() throw() {};

	virtual void Run();
	void BindSocket(int node_index);

private:
	int node_index_;
	static int cur[MAX_CPU_NUM];	// indicate current CPU in every node
};

class DestroyTask: public Task {
public:
	DestroyTask():Task(NULL, NULL){};
	~DestroyTask() throw() {}
	void Run() {
		Logs::log("pthread_exit...\n");
		pthread_exit(NULL);
	}
};

#endif /* SIMPLETHREADPOOL_TASK_H_ */
