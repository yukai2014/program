/*
 * MemoryPoolTest.cpp
 *
 *  Created on: 2014-10-27
 *      Author: imdb
 */

#include <iostream>
#include <string.h>
#include "MemoryPool.h"
using namespace std;

int main(){
	struct timeval start, end;

	size_t chunk_size = 2*1024*1024;
	MemoryPool *mp = MemoryPool::GetInstance();
	mp->CreateMemoryPool(chunk_size);
	mp = MemoryPool::GetInstance();
	mp = MemoryPool::GetInstance();
/*
	{
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
		{
			a = (char*)mp->KMalloc(100 * sizeof(char));
			cout<<static_cast<void *>(a)<<endl;
			cout<<a[0]<<"-"<<a[1]<<endl;
			memset(a, 0, sizeof(char) * 100);
			cout<<(int)a[0]<<"-"<<(int)a[1]<<endl;
			a[0] = 'c';
			a[1] = 'd';
			cout<<a[0]<<"-"<<a[1]<<endl;
		}

		mp->ResetMemoryPool();
		{
			a = (char*)mp->KCalloc(100 * sizeof(char));
			cout<<static_cast<void *>(a)<<endl;
			cout<<a[0]<<"-"<<a[1]<<endl;
			memset(a, 0, sizeof(char) * 100);
			cout<<(int)a[0]<<"-"<<(int)a[1]<<endl;
			a[0] = 'f';
			a[1] = 'g';
			cout<<a[0]<<"-"<<a[1]<<endl;
		}
	}
	*/
	int k = 100;
	double kmalloc_time = 0;
	double malloc_time = 0;
	double malloc_free_time = 0;
	double destroy_time = 0;
	double reset_time = 0;
	while (k--)
	{
		char *m;
		srand(10 * time(NULL));
		int i;
		int size[10000];
		memset(size, 0, sizeof(size));
		for (i = 0; i < 10000; ++i) {
			size[i] = rand() % 1000 +10;
		}





		gettimeofday(&start, NULL);
		for (i = 0; i < 10000; ++i) {
			m = (char*)malloc(size[i] * sizeof(char));
			free(m);
		}
		gettimeofday(&end, NULL);
//		cout<<"malloc free use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
		malloc_free_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;






		char c[] = "1";
		gettimeofday(&start, NULL);
		for (i = 0; i < 10000; ++i) {
			m = (char*)mp->KMalloc(size[i] * sizeof(char));
			if (m == NULL) {
				ELOG("kmalloc error");
				break;
			}
//			cout<<(void*)m<<endl;
			strcpy(m, c);
		}
		gettimeofday(&end, NULL);
//		cout<<"KMalloc use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
		kmalloc_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;

//		cout<<"destroy memory pool"<<endl;
		gettimeofday(&start, NULL);
		mp->ResetMemoryPool();
		gettimeofday(&end, NULL);
//		cout<<"reset use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
		reset_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;

/*
		gettimeofday(&start, NULL);
		for (i = 0; i < 10000; ++i) {
			m = (char*)malloc(size[i] * sizeof(char));
			if (m == NULL) {
				cout<<"malloc error"<<endl;
				break;
			}
			strcpy(m, c);
		}
		gettimeofday(&end, NULL);
//		cout<<"malloc use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
//		if ((double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000 < 0) {
//			cout<<"      "<<"start sec:"<<start.tv_sec<<"- end sec:"<<end.tv_sec<<" "<<(end.tv_sec - start.tv_sec) * 1000<<endl;
//			cout<<"      "<<"start sec:"<<start.tv_usec<<"- end sec:"<<end.tv_usec<<" "<<(double)(end.tv_usec - start.tv_usec)/1000<<endl;
//		}
		malloc_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;
*/


	}

	gettimeofday(&start, NULL);
	mp->DestroyMemoryPool();
	gettimeofday(&end, NULL);
	//		cout<<"Destroy use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
	destroy_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;

	cout<<"malloc:"<<malloc_time<<endl;
	cout<<"malloc_free:"<<malloc_free_time<<endl;
	cout<<"kmalloc:"<<kmalloc_time<<endl;
	cout<<"reset:"<<kmalloc_time<<endl;
	cout<<"destroy:"<<destroy_time<<endl;

	//	mp->DestroyMemoryPool();
	//	while(1);
	return 0;
}
