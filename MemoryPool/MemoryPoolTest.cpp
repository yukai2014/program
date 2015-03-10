/*
 * MemoryPoolTest.cpp
 *
 *  Created on: 2014-10-27
 *      Author: imdb
 */

#include <iostream>
#include <string.h>
#include <algorithm>
#include <pthread.h>
#include "MemoryPool.h"
using namespace std;

struct kk {
	int index_pp;
	char** p;
	MemoryPool* mp;
};
void* GetMemory(void* arg) {
	struct kk *k = ((struct kk*)arg);
	MemoryPool *mp = (MemoryPool*)(k->mp);
	char **pp = (char**)k->p;
	cout<<"pp:"<<(void*)pp<<endl;

	int index_pp = k->index_pp;
	srand((unsigned)time(NULL));
	int i = 0;
	int size = 0;
	while (i < 100) {
		size = rand()%1000+1;
		*pp = (char*)mp->KCalloc(size);
		pp = pp + 1;
		++i;
	}
	return NULL;
}


int lock_time = 0;

int main(){
	struct timeval start, end;

	size_t chunk_size = 2*1024*1024;
	MemoryPool *mp = MemoryPool::GetInstance();
	mp->CreateMemoryPool(chunk_size);
	mp = MemoryPool::GetInstance();
	mp = MemoryPool::GetInstance();
	{// testing multi-thread
		char *p[1000];
		memset(p, 0, sizeof(p));
		cout<<"p[0]:"<<(void*)p[0]<<" p:"<<(void*)p<<endl;
		kk k1, k2, k3, k4, k5;
		pthread_t p1, p2, p3, p4, p5;

		k1.mp = mp;
		k1.index_pp = 0;
		k1.p = p;
		cout<<"k1.p:"<<(void*)k1.p<<endl;
		pthread_create(&p1, NULL, GetMemory, &k1);

		k2.mp = mp;
		k2.index_pp = 100;
		k2.p = p + 100;
		cout<<"k2.p:"<<(void*)k2.p<<endl;
		pthread_create(&p2, NULL, GetMemory, &k2);

		k3.mp = mp;
		k3.index_pp = 200;
		k3.p = p + 200;
		cout<<"k3.p:"<<(void*)k3.p<<endl;
		pthread_create(&p3, NULL, GetMemory, &k3);

		k4.mp = mp;
		k4.index_pp = 300;
		k4.p = p + 300;
		cout<<"k4.p:"<<(void*)k4.p<<endl;
		pthread_create(&p4, NULL, GetMemory, &k4);

		k5.mp = mp;
		k5.index_pp = 400;
		k5.p = p + 400;
		cout<<"k5.p:"<<(void*)k5.p<<endl;

		pthread_create(&p5, NULL, GetMemory, &k5);

		pthread_join(p1, NULL);
		pthread_join(p2, NULL);
		pthread_join(p3, NULL);
		pthread_join(p4, NULL);
		pthread_join(p5, NULL);

		sort(p, p+499 );
		for (int i = 0; i < 500; ++i) {
			cout<<(void*)p[i]<<endl;
			if (i > 0 && p[i] == p[i-1]) {
				cout<<endl<<"same!!!!!!!!!!!!!"<<endl;
				break;
			}
		}

		mp->DestroyMemoryPool();
		return 0;
	}

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
/*
	{	test malloc/malloc-free/kmalloc performance
		int k = 10000;
		double kmalloc_time = 0;
		double malloc_time = 0;
		double malloc_free_time = 0;
		double destroy_time = 0;
		double reset_time = 0;
		char c[] = "1";
		bool error = false;

		while (k--)
		{
			int peer_count = 100;
			char *m;
			srand(10 * time(NULL));
			int i;
			int size[10000];
			memset(size, 0, sizeof(size));
			for (i = 0; i < peer_count; ++i) {
				size[i] = rand() % 1000 +10;
			}

			{
				gettimeofday(&start, NULL);
				for (i = 0; i < peer_count; ++i) {
					m = (char*)malloc(size[i] * sizeof(char));
					if (m == NULL) {
						ELOG("malloc error");
						error = true;
						break;
					}
					strcpy(m, c);
					free(m);
				}
				gettimeofday(&end, NULL);
				//		cout<<"malloc free use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
				malloc_free_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;
			}


			{
				gettimeofday(&start, NULL);
				for (i = 0; i < peer_count; ++i) {
					m = (char*)mp->KMalloc(size[i] * sizeof(char));
					if (m == NULL) {
						ELOG("kmalloc error");
						error = true;
						break;
					}
					//			cout<<(void*)m<<endl;
					strcpy(m, c);
				}
				gettimeofday(&end, NULL);
				//		cout<<"KMalloc use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
				kmalloc_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;
			}

			{
				gettimeofday(&start, NULL);
				mp->ResetMemoryPool();
				gettimeofday(&end, NULL);
				//		cout<<"reset use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
				reset_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;
			}
			{
				gettimeofday(&start, NULL);
				for (i = 0; i < peer_count; ++i) {
					m = (char*)malloc(size[i] * sizeof(char));
					if (m == NULL) {
						cout<<"malloc error"<<endl;
						error = true;
						break;
					}
					strcpy(m, c);
				}
				gettimeofday(&end, NULL);
				malloc_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;
			}


		}
		//		cout<<"destroy memory pool"<<endl;
		gettimeofday(&start, NULL);
		mp->DestroyMemoryPool();
		gettimeofday(&end, NULL);
		//		cout<<"Destroy use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
		destroy_time += (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;

		if (error)
			cout<<"error!!!!!!!!!!!!"<<endl;

		cout<<"lock "<<lock_time<<" times"<<endl;
		cout<<"malloc:"<<malloc_time<<endl;
		cout<<"malloc_free:"<<malloc_free_time<<endl;
		cout<<"kmalloc:"<<kmalloc_time<<endl;
		cout<<"reset:"<<reset_time<<endl;
		cout<<"destroy:"<<destroy_time<<endl;
	}
	*/
	return 0;
}
