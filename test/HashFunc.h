/*
 * HashFunc.h
 *
 *  Created on: 2014-11-12
 *      Author: imdb
 */

#ifndef HASHFUNC_H_
#define HASHFUNC_H_

#include <stdio.h>

uint Hash1(int a, int b) {	//  Szudzik's function
	long int la = (long)a;
	long int lb = (long)b;
	long int result = 0;
	result = (la > lb? la * la + la + lb: la + lb * lb)/2;
	return result & 0x000FFFFF;
}

uint Hash2(int a, int b) {
	uint result = 0;
	result = (a & 0x1f1f1f1f) ^ b;
	return result & 0x000FFFFF;
}

uint Hash3(int a, int b) {
	int res = 0x7e53a269;
	res = (-1521134295 * res) + a;
	res += (res << 10);
	res ^= (res >> 6);

	res = ((-1521134295 * res) + b);
	res += (res << 10);
	res ^= (res >> 6);

	return res & 0x000FFFFF;
}

uint Hash4(int a, int b) {	//  Cantor Pairing Function (wiki)	// best !!!!!
	return ((a + b) * (a + b + 1)/2 + b) & 0x000FFFFF;
}

uint Hash5(int a, int b) {	// worst
	int max1 = a > b? a: b;
	int max2 = b > 2*b - a? b: 2*b - a;
	return (max1 + max2) & 0x000FFFFF;
}

uint Hash6(int a, int b) {
	int r1 = a + (a<<2) + (a<<11) + (a>>3) + (a>>7);
	int r2 = b + (b<<2) + (b<<11) + (b>>3) + (b>>7);
	return (r1 + r2) & 0x000FFFFF;
}
static int num = 0;

void TestHashFunc(uint (*f)(int a, int b)) {
	num++;
	cout<<num<<endl;
	int bucket[0x00100000];
	memset(bucket, 0, sizeof(bucket));
//	File *file = fopen("/home/imdb/TestMysql/bigdata","r");
//	fread();
	ifstream ifs("/home/imdb/TestMysql/bigdata");
//	ifs.open();
	int a, b, i;
	int res;
	struct timeval start, end;
	gettimeofday(&start, NULL);
	while (ifs>>a>>b) {
		res = f(a,b);
		++bucket[res];
	}
	gettimeofday(&end, NULL);
	double time = (double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000;

	int empty = 0;
	int min_bucket_size = 100000;
	int max_bucket_size = 0;
	int bucket_num_in_size[10000];
	memset(bucket_num_in_size, 0, sizeof(bucket_num_in_size));

	for (i = 0; i < 0x00100000; ++i) {
		if (bucket[i] == 0) {
			++empty;
		}
		max_bucket_size = max_bucket_size > bucket[i]? max_bucket_size: bucket[i];
		min_bucket_size = min_bucket_size < bucket[i]? min_bucket_size: bucket[i];
		++bucket_num_in_size[bucket[i]];
	}

	ofstream ofs("/home/imdb/TestMysql/hash_result", ofstream::app);

	ofs<<endl;
	ofs<<endl;
	ofs<<num<<"===="<<time<<endl;
	ofs<<endl;
	ofs<<"empty bucket num :"<<empty<<endl;
	ofs<<"max num in a bucket :"<<max_bucket_size<<endl;
	ofs<<"min num in a bucket :"<<min_bucket_size<<endl;

//	for (i = 0; i < 300; ++i) {
////		if (bucket_num_in_size[i] != 0) {
////			ofs<<"bucket num which has "<<i<<"item is:"<<bucket_num_in_size[i]<<endl;
//			ofs<<bucket_num_in_size[i]<<endl;
////		}
//	}
	cout<<num<<endl;
}

#endif /* HASHFUNC_H_ */
