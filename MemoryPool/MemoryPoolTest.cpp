/*
 * MemoryPoolTest.cpp
 *
 *  Created on: 2014-10-27
 *      Author: imdb
 */

#include <iostream>
#include "MemoryPool.h"
using namespace std;

int main(){
	size_t size = 2*1024*1024;
	MemoryPool *mp = MemoryPool::GetInstance();
	mp->CreateMemoryPool(size);
	mp = MemoryPool::GetInstance();
	mp = MemoryPool::GetInstance();

	char *a = NULL;
	int count = 1100;
	while (count--) {
		a = (char*)mp->KMalloc(4000);
		memset(a, 0, sizeof(1000));
		if (count >= 1080)
			cout<<static_cast<void*>(a)<<endl;
	}
	a = (char*)mp->KMalloc(100);
	a[0] = '1';
	a[1] = '2';
	cout<<static_cast<void *>(a)<<endl;
	a = (char*)mp->KMalloc(200);
	a[0] = '1';
	a[1] = '2';
	cout<<static_cast<void *>(a)<<endl;
	a = (char*)mp->KMalloc(1000);
	a[0] = '1';
	a[1] = '2';
	count = 3;
	while (count--) {
		cout<<static_cast<void *>(a)<<endl;
		a= (char*)mp->KMalloc(100000);
		a[0] = '1';
		a[1] = '2';
		a[2] = '3';
		a[98] = 'a';
		a[99999] = 'e';
		cout<<static_cast<void *>(a)<<endl;
		cout<<a[99999]<<endl;
	}

	mp->ResetMemoryPool();
	mp->ResetMemoryPool();
	cout<<"-----------reset ok-----------"<<endl;
	count = 1100;
	while (count--) {
			a = (char*)mp->KMalloc(4000);
			memset(a, 0, sizeof(1000));
			if (count >= 1080)
				cout<<static_cast<void*>(a)<<endl;
		}
	a = (char*)mp->KMalloc(100 * sizeof(char));
	cout<<static_cast<void *>(a)<<endl;
	cout<<a[0]<<"-"<<a[1]<<endl;
	memset(a, 0, sizeof(char) * 100);
	cout<<(int)a[0]<<"-"<<(int)a[1]<<endl;
	a[0] = 'a';
	a[1] = 'b';
	cout<<a[0]<<"-"<<a[1]<<endl;
	mp->DestroyMemoryPool();
	while(1);
	return 0;
}
