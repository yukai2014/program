#include "HashFunc.h"

using namespace std;

/**
 * hashCode method:	http://docs.oracle.com/javase/8/docs/api/java/lang/String.html#hashCode--
 * s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]
 */
unsigned int HashA(const std::string& s)
{

	unsigned int key = 0;
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		key += s[i] * (unsigned)pow(31, n-1-i);
	}
	return key;
}

/**
 *  FNV-1a hash:	http://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash
 */
unsigned int HashB(const std::string& s)
{
	unsigned int hash = 2166136261U;
	for (int i = 0; i < s.length(); ++i) {
		hash ^= (unsigned)s[i];
		hash += (hash<<1) + (hash << 4) + (hash << 7) + (hash<<8) + (hash<<24);
	}
	return hash;
}

/**
 * Jenkins hash function:	http://en.wikipedia.org/wiki/Jenkins_hash_function
 */
unsigned int HashC(const std::string& s)
{
	unsigned int hash = 0, i = 0;
	unsigned int len = s.length();
	for(i = 0; i < len; ++i)
	{
		hash += s[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}
