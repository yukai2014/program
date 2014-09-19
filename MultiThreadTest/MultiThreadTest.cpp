//============================================================================
// Name        : MultiThreadTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <pthread.h>
using namespace std;

int id = 0;

void* AllocateId(void * meaningless)
{
	cout<< ++id<<endl;
	return (void*)0;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	pthread_t p1, p2, p3;
	pthread_create(&p1, NULL, &AllocateId, NULL);
	pthread_create(&p2, NULL, &AllocateId, NULL);
	pthread_create(&p3, NULL, &AllocateId, NULL);// cout<< "1		2		2" or " 1	3	2" or "1 2 3"

//	pthread_join(p1,NULL);
//	pthread_join(p2,NULL);
//	pthread_join(p3,NULL);

	return 0;
}
