/**
 * A hash set.
 * Stub written by James Daly, 8 Oct 2014
 * Completed by [YOUR NAME]
 */
#pragma once

#ifndef HASH_SET_H
#define HASH_SET_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

static int ii = 0;

template<class T>
class HashSet
{
public:
	HashSet(std::function<unsigned int(const T&)> hash, double loadFactor);
	HashSet(HashSet<T> &other);
	virtual ~HashSet();
	
	// Supplied Methods
	bool IsEmpty() { return Size() == 0; }
	unsigned int Size() { CheckSize(__LINE__); return size; }
	double GetLoadFactor() { return loadFactor; }
	void DisplayItems() { ForEach([](const T& item) { std::cout << item << std::endl; }); }
	double GetLoad() { return ((double)Size()) / (double)NumBuckets(); }
	
	// Methods that you must complete
	unsigned int NumBuckets() { return bucket_num; }
	bool Contains(const T& item) const;
	bool Insert(const T &item);
	bool Remove(const T &item);
	void Clear();
	void ForEach(std::function<void (const T&)> func);
	unsigned int MaxBucketSize();
	double PercentEmptyBuckets();
	
	void CheckSize(int line){
		ii++;
		unsigned int sum = 0;
		for (auto bucket:buckets) {
			sum += bucket.size();
		}
		if (sum != size) {
			cout<<"error! in line "<<line<<"size is :"<<size<<" real size is"<<sum<<endl;
		}
//			if (ii % 100 == 0) getchar();
	}

	void DisplayBucket() {
		unsigned int i = 0;
		for (i = 0; i < buckets.size(); ++i) {
			cout<<i<<" bucket has "<<buckets.at(i).size()<<"	item"<<endl;
//			for (auto item:buckets.at(i)) {
//				cout<<"	"<<item<<endl;
//			}
		}
	}

private:
	unsigned int size;	// the number of item
	double loadFactor;	// the mean number of items per bucket
	std::function<unsigned int (const T&)> hash;
	// You need some data source to store items
	vector<vector<T>> buckets;
	unsigned int bucket_num;


	// You can put any helper methods here
};

/**
 * Default constructor
 */
template<class T>
HashSet<T>::HashSet(std::function<unsigned int(const T&)> hash, double loadFactor):
	size(0),
	loadFactor(loadFactor),
	hash(hash)
{
	// Empty: You can put other initialization information here
	bucket_num = 5;
	Clear();
	for (unsigned int i = 0; i < bucket_num; ++i) {
		vector<T> bucket;
		bucket.clear();
		buckets.push_back(bucket);
	}
}

/**
 * Copy Constructor
 * Uses uniform instantiation to initialize itself
 * and then copies all of the items from the other set
 */
template<class T>
HashSet<T>::HashSet(HashSet<T> &other) :
	HashSet(other.hash, other.loadFactor)
{
	Clear();
	bucket_num = other.NumBuckets();
	for (unsigned int i = 0; i < bucket_num; ++i) {
		vector<T> bucket;
		bucket.clear();
		buckets.push_back(bucket);
	}
	auto insertItem = [=](const T& x){ this->Insert(x); };
	other.ForEach(insertItem);
}

/**
 * Destructor
 * Any cleanup you need to do can be done here
 */
template<class T>
HashSet<T>::~HashSet()
{
	// Empty: You can put any steps necessary for cleanup here
	Clear();
}

/**
 * Returns true iff the item is in the set
 */
template<class T>
bool HashSet<T>::Contains(const T &item) const
{
	// TODO
	unsigned int key = hash(item) % bucket_num;
	vector<T> bucket = buckets.at(key);
	for (auto it : bucket) {
		if (it == item) {
			return true;
		}
	}
	return false;
}

/**
 * Inserts the item into the set.
 * Only one copy can exist in the set at a time.
 * Returns true iff the item was successfully added.
 */
template<class T>
bool HashSet<T>::Insert(const T &item)
{
	// check whether set has this item
	if (Contains(item) == true) {
//		cout<<"has had item:"<<item<<endl;
		return false;
	}

	if (GetLoad() > loadFactor) {
		//  increase the number of buckets and rehash the set
		vector<T> temp;
		temp.clear();
//		void func(const T&){};
//		ForEach([=](const T& it){temp.push_back(it)});

		for (auto bucket = buckets.begin(); bucket != buckets.end(); ++bucket) {
			for (auto item = bucket->begin(); item != bucket->end(); ++item) {
				temp.push_back(*item);
			}
			bucket->clear();
		}
/*
 *
		for (auto bucket:buckets) {
			for (auto item:bucket) {
				temp.push_back(item);
			}
			bucket.clear();	// useless, don't know why
		}
		typename vector<vector<T>>::iterator it;
		for (it = buckets.begin(); it != buckets.end(); ++it) {
			it->clear();
		}
*/

		size = 0;
		CheckSize(__LINE__);

		bucket_num += 5;
		for (int i = 0; i < 5; ++i) {
			vector<T> bucket;
			bucket.clear();
			buckets.push_back(bucket);
		}
//		cout<<"add 5 bucket"<<endl;

		for(auto it : temp) {
			this->Insert(it);
		}

		this->Insert(item);

	}
	else {
		// push into bucket directly
		unsigned int key = hash(item) % bucket_num;
		buckets.at(key).push_back(item);
		++size;
		CheckSize(__LINE__);
	}
	return true;
}

/**
 * Removes the item from the set.
 * Returns true iff the item was successfully removed.
 */
template<class T>
bool HashSet<T>::Remove(const T &item)
{
	if (Contains(item) == false)
		return false;
	unsigned int key = hash(item) % bucket_num;
	for (auto it = buckets.at(key).begin(); it != buckets.at(key).end(); ++it) {
		if (*it == item) {
			buckets.at(key).erase(it);
			--size;
			CheckSize(__LINE__);
			return true;
		}
	}
	assert(false);
}

/**
 * Removes all elements from the set.
 */
template<class T>
void HashSet<T>::Clear()
{
	for (auto bucket:buckets){
		bucket.clear();
	}
	buckets.clear();
	size = 0;
	CheckSize(__LINE__);
}

/**
 * Invokes the function once on each item in the set.
 * The exact order is undefined.
 */
template<class T>
void HashSet<T>::ForEach(std::function<void (const T&)> func)
{
	for (auto bucket = buckets.begin(); bucket != buckets.end(); ++bucket) {
		for (auto it = bucket->begin(); it != bucket->end(); ++it) {
			func(*it);
		}
	}
}

/**
 * Finds the maximum number of items in a bucket.
 */
template<class T>
unsigned int HashSet<T>::MaxBucketSize()
{
	unsigned int max_bucket_size = 0;
	for (auto bucket : buckets) {
		max_bucket_size = max_bucket_size > bucket.size()? max_bucket_size: bucket.size();
	}
	return max_bucket_size;
}

/**
 * Finds which fraction of the buckets are empty
 * The result is returned as a percent
 */
template<class T>
double HashSet<T>::PercentEmptyBuckets()
{
	int empty_num = 0;
	int i = 0;
//	buckets.empty();
	for (auto bucket : buckets) {
		++i;
		if (bucket.empty()) {
//			cout<<"bucket "<<i<<" is empty"<<endl;
			empty_num++;
		}
//		else {
//			cout<<"bucket "<<i<<" is not empty"<<endl;
//		}
	}
	return (double)100.0 * empty_num / bucket_num;
}

#endif
