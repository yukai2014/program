/*
 * test.cpp
 *
 *  Created on: 2014-9-20
 *      Author: imdb
 */


#include <iostream>
#include <malloc.h>
#include <algorithm>
#include <unistd.h>
#include <bitset>
#include <limits>
#include <cstring>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <sys/time.h>
#include <map>
#include <set>
#include <sstream>
#include <pthread.h>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/map.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/archive/tmpdir.hpp>

#include "../test/MemoryLayoutOfClass.h"
//#include "testsf.cpp"

using namespace std;
//#pragmapack(4)
class kong{
public:
	virtual void PrintNum() const{
		cout<<"kong"<<endl;
	};	// 8	-->8
	inline void abc(){
		a = 1;
	}
	int a;	// 4	-->12
	char b;	// 1	-->16
	double c;// 8	-->24
	int ba;	// 4	-->32
};

class bird
{
public:
	bird(){
		num = 1;
//		cout<<"a bird"<<endl;
	}
	virtual void PrintNum()	// 8	-->8
	{
		cout<<"bird is "<<num<<endl;
	}
private:
	//	double num;	// 4	-->16
	int num;
};

/*
 * kongbird:
 * 			vtable* ----> 指向kong 的虚函数表	// 8 --- 8
 * 			vtable* ----> 指向 bird的虚函数表	// 8 --- 16
 * 		----------------------- 接下来是kong的成员
 * 			int a;									// 4	-->20
 * 			char b;									// 1	-->24
 * 			double c;								// 8	-->32
 * 			int ba;									// 4	-->36
 * 		----------------------- 接下来是bird的成员
 * 			int num;									// 4 --- 40
 * 		----------------------- 接下来是bird的成员
 * 			int temp；								// 4 --- 48
 *
 *	如果改num为double， 则sizeof（kongbird）为56
 */
class kongbird: public bird, public kong
{
private:
	int temp;
	void PrintNum() const{
		cout<<"kb"<<endl;
	}
};

class FlyBird: public bird
{
	friend bool feed();

public:
	//	FlyBird() = default;
	FlyBird(const int init):test_for_init(init){}
	/*	FlyBird(){
		new_number = 11;
//		cout<<num<<endl;
		cout<<new_number<<endl;
	}*/
	bool feed();
	void print(){
		cout<<"fly bird num is"<<num<<endl;
		PrintNum();
	}
private:
	int new_number;
	const int test_for_init;
	int num;
};

bool FlyBird::feed()
{
	new_number = 1;
	return 1;
}

class NoDefault
{
public:
	NoDefault(int i):ii(i){}
	//	NoDefault(){}
	void print_mem(){
		cout<<"the member of NoDefault is :"<<ii<<endl;
	}
	void DeleteSelf();
private:
	int ii;
};

void NoDefault::DeleteSelf()
{
	delete this;
	cout<<"delete successfully"<<endl;
}

class C
{
public:
	//	C(NoDefault nd = NoDefault(0)):d(nd){}	// OK, this is default constructor
	C():d(NoDefault(3.5)){}	// OK, this is also default constructor
	void print_mem(){
		cout<<"ok "<<endl;
		d.print_mem();
	}
private:
	NoDefault d;
};

struct Node//基本节点
{
	int * p;
	int type;
	char *d;
	Node(int i): type(i){}

	friend void operator<<(ostream& os, Node &n)
	{
		os<<n.type;
	}

	//	istream &operator >>(istream &is, Node n)
};

bool IsSmaller(const Node &a, const Node &b)
{
	return a.type < b.type;
}

void operator>>(istream& is, Node &n)
{
	//		istream is;*(n.p)>>
	is>>n.type;
}

Node *pp[10];

Node * newNode(int i)
		{
	Node *p1= (Node *)malloc(sizeof(Node));
	p1->type = 1;
	pp[i] = p1;
	return p1;
		};

int xx = 5;
int f() {
	int xx = 3;
	{
		extern int xx;
		cout<<xx<<endl;
		return xx;
	}
}
enum valueType{t_int, t_float, t_double};
template<class T>
void SaveSth(const T t, const char* filename)
{
	std::ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	oa << t;
}

template<class T>
void RestoreSth(const T t, const char* filename)
{
	std::ifstream ifs(filename);
	boost::archive::text_iarchive ia(ifs);
	ia >> t;
}

void SaveSth(const int &x, const char *filename )
{
	std::ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	oa << x;
}

void RestoreSth(int &x, const char *filename)
{
	std::ifstream ifs(filename);
	boost::archive::text_iarchive ia(ifs);
	ia >> x;
}

// test the serialization of enum type
void SaveSth(const valueType &x, const char *filename )
{
	std::ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	oa << x;
}

void RestoreSth(valueType &x, const char *filename)
{
	std::ifstream ifs(filename);
	boost::archive::text_iarchive ia(ifs);
	ia >> x;
}

int _g;

int get_int_from_void(void *arg)
{
	return *(int *)arg;
}

class TestForReturnConst
{
public:
	const vector<int>& getV() const{
		return V;
	}
private:
	vector<int> V;
};

void insert(ostringstream &ostr, int i)
{
	ostr<<i;
}

const string file_name = "a.txt";

void *WriteFile(void *arg)
{
	char s = *(char*)arg;
	ofstream ofs("a.txt", ofstream::app);

	int i = 10000;
	while (--i)
	{
		ofs<<s;
	}
	return (void *)0;
}

int global;
int global_init = 0;

//
//char *get() {
//	char p[]="jelelo";
//	return p;
//}


class CC{
public:
	void print_mem(){
		cout<<"p[["<<endl;
	}
};


void  aaa(vector<CC*>& ccc){
	CC c;
	CC* p = new CC();
	cout<<"CC c：   "<<&c<<endl;
	cout<<"new CC： "<<p<<endl;
	ccc.push_back(&c);
	ccc.push_back(p);
}

int main() {
	{
		MemeoryLayoutOfClassDemon demon;
		demon.show();
	}
	{
		{	// 小端字节序，比如a = 0x00000004， 在内存中就是存为 0x04,0x00，0x00，0x00
			int a = 4;
			int *p = &a;
			char *cp = (char*)p;
			cout<<(int)((char*)p)[0]<<(int)cp[1]<<(int)cp[2]<<(int)cp[3]<<endl;
			char *buffer = (char*)malloc(8);
			*(int*)buffer = a;
			cout<<(int)buffer[0]<<"--"<<(int)buffer[1]<<"--"<<(int)buffer[2]<<"--"<<(int)buffer[3]<<endl;	// 4--0--0--0
		}

		int kk = 0x01030012;
		int *pp = &kk;
		cout<<int(*(((char*)pp)+0))<<"--"<<int(*(((char*)pp)+1))<<"--"<<int(*(((char*)pp)+2))<<"--"<<int(*(((char*)pp)+3))<<endl;	// 18--0--3--1
		cout<<kk<<endl;		// 16973842
		cout<<"----"<<endl;

		long i[2];
		i[0] = 0x0000000200000001;
		i[1] = 0x0000000200001001;
		long **p = (long**)&i;

//		cout<<(((int*)p)+k)<<endl;
		cout<<int(*(((int*)p)+0))<<"--"<<int(*(((int*)p)+1))<<"--"<<int(*(((int*)p)+2))<<"--"<<int(*(((int*)p)+3))<<endl;	// 1--2--4097--2
	}
	{
		cout<<"kong:		"<<sizeof(kong)<<endl;
		cout<<"bird:		"<<sizeof(bird)<<endl;
		cout<<"kongbird:	"<<sizeof(kongbird)<<endl;
		//		kongbird kb;
		bird *p = new kongbird();
		p->PrintNum();			//子类和基类的虚函数必须一致，包括是否为const，否则仍调用bird的方法，因为子类的虚函数会覆盖另一基类的虚函数
		//kb.PrintNum();		// 歧义，两个基类都有该虚函数
				return 0;
	}


	{
		char *a = "dfs";
		a += 2;
		string aa;
		aa = string(a);
		cout<<aa.length()<<"--"<<aa<<endl;	// “s”
		cout<<sizeof(a)<<"--"<<a[3]<<endl;
		return 0;

		//		for (long i = (long)a-200; i < (long)a+3; i++) {
		//						char *t = (char*)i;
		//						printf("%ld:%p:%c\n", i, t, *t);
		//					}
	}
	/*	{
		vector<CC*> ccc;
		aaa(ccc);
		cout<<&(ccc.at(0))<<endl;	// 在函数中push指针的类对象仍存在vector中，在push时候重新在堆中复制构造了指向的类对象
		cout<<&(ccc.at(1))<<endl;	// 地址位于堆中
	}*/

	/*	{
		int line = __LINE__;
		string filename = __FILE__;
		cout<<"the line is:"<<line<<endl;	//输出当前行
		cout<<"the filename is :"<<filename<<endl;	//输出当前文件名
	}*/

	{ //	http://blog.csdn.net/sgbfblog/article/details/7772153 图很好，也有解释

		{//无论初始化了没有，都是存储在栈。
			int a;			// 栈
			int b = 2;		// 栈
			printf("a:			%p\n", &a);
			printf("b:			%p\n", &b);
			int s[5];				// 栈
			int ss[5] = {0};		// 栈
			printf("s:			%p\n", s);
			printf("ss:			%p\n", ss);
			char init[] = "abc";
			printf("init:			%p\n", init);
		}

		{// global, global_init, uninitialized, initialized都是存储在全局/静态存储区
			printf("global:		%p\n", &global);
			printf("global_init:	%p\n", &global_init);

			static int uninitialized;
			static int initialized = 0;
			static int uninitialized1;
			static int initialized1 = 0;
			printf("initialized:	%p\n", &initialized);
			printf("uninitialized:	%p\n", &uninitialized);
			printf("initialized1:	%p\n", &initialized1);
			printf("uninitialized1:	%p\n", &uninitialized1);

			//			static char *uninit;		// is NULL
			static char static_init[] = "abc";
			//			printf("uninit:		%p\n", uninit);
			printf("static_init:	%p\n", static_init);
		}
		{
			//			static
			char *const_init = "abc";	// 文字常量存储区
			printf("const_init:		%p\n", const_init);
			printf("abc:			%p\n", &"abc");
			printf("def:			%p\n", &"def");
			// 接下来是查看这一片内存存放的内容
			//			"abc";
			//			"def";
			//			for (long i = (long)&"abc"-10; i < (long)&"def"+3; i++) {
			//				char *t = (char*)i;
			//				printf("%ld:%p:%c\n", i, t, *t);
			//			}
		}
		{// malloc 分配哪里的内存,很大和很小的分别为两个地方的内存，默认小余128kB内存使用brk（）在堆中分配，大内存使用mmap（）在映射区分配内存
			int *p1 = (int *)malloc(100*sizeof(int));		// 堆
			int *p2 = (int *)malloc(1000000*sizeof(int));	// 映射区	---->准确说是虚拟内存
			printf("p1:			%p\n", p1);
			printf("p2:			%p\n", p2);
			free(p1); free(p2);

			// new is same as malloc
			int *new1 = new int[5];
			int *new2 = new int[10000000];
			printf("new1:			%p\n", new1);
			printf("new2:			%p\n", new2);
			delete(new1); delete new2;
		}
	}
	{
		cpu_set_t cpu_set;
		CPU_ZERO(&cpu_set);		// 在标准库中
	}
	{
		cout<<"kong: "<<sizeof(kong)<<endl;
	}

	/*
	{
		int b = 123;
		int &a = b;
		cout<<&b<<"==="<<&a<<endl; // equal!!!
	}
	 */
	{
		//concurrent write file
		pthread_t thread1, thread2;
		char a = 'a';
		char b = 'b';
		pthread_create(&thread1, NULL, &WriteFile, &a);
		pthread_create(&thread2, NULL, &WriteFile, &b);

		/* result likes this:
		 *  bbbbbbbbbbbbaaaaaaaaaaaaaaabbbbaaaa
		 */
	}

	{
		bird a;
		FlyBird b(10);
		b.print();
	}

	Node a(1);
	{
		Node a(152);
		Node b(14);
		multiset<int, bool (*)(const Node &a, const Node &b)> ms(IsSmaller);	//自定义结构
		ms.insert(a.type);
		ms.insert(b.type);

		ostream_iterator<int> ostr_iter(cout, " ");
		copy(ms.begin(), ms.end(), ostr_iter);
		cout<<endl;
	}
	{//测试在成员函数内加入 delete自身，结果很奇怪
		NoDefault *a = new NoDefault(2);
		a->DeleteSelf();
		if (a)
		{
			a->print_mem();
		}
		//		delete a;

		//		NoDefault b(11);
		//		b.DeleteSelf();
		//		b.print_mem();
	}
	{
		//计时
		timeval start, end;
		gettimeofday(&start, NULL);
//		clock_t s = clock();
		//		sleep(1);
		int i = 1000000;
		while (--i) {};
		gettimeofday(&end, NULL);	// 可用
//		clock_t e = clock();

		//		cout<<"start "<<start.tv_sec*1000000+start.tv_usec<<"; end: "<<end.tv_sec*1000000+end.tv_usec<<endl;

		//		cout<<s<<" "<<e<<endl;
		//		cout<<(double)(e-s)/1000<<" ms"<<endl;
		cout<<end.tv_sec-start.tv_sec<<"second "<<end.tv_usec-start.tv_usec<<" microsecond"<<endl;
	}

	//	{//流迭代器 处理 可用
	//		Node nn;
	////		cin>>nn;
	//		istream_iterator<Node> iut_iter(cin), eof;
	//		while (iut_iter != eof){
	//			Node n = *iut_iter++;	//用cin>>n 赋值
	//
	//			ostream_iterator<int> out_iter(cout);
	//			*out_iter++ = n.type;
	//			cout<<endl;
	//		}
	//	}

	{
		vector<int> v(10, 1);
		fill(v.begin(),v.end(), 23);
		for (int i = 0; i < 10; ++i)
			v.push_back(i);
		for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
			cout<<*it<<"-";
		//		for_each(v.begin(), v.end(), [](const int t){return t;});
		cout<<endl;

		// Usage of ostream_iterator
		ostream_iterator<int> out_iter(cout, " ");
		// one
		for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
			*out_iter++ = *it;	// *out_iter, out_iter++ all return out_iter
		cout<<endl;
		//two
		copy(v.begin(),v.end(),out_iter);
		cout<<endl;

		sort(v.begin(), v.end());
		copy(v.begin(), v.end(), out_iter);
		cout<<endl;

		sort(v.rbegin(), v.rend());
		copy(v.begin(), v.end(), out_iter);
		cout<<endl;
	}

	{	//数组不支持begin和end
		//		int a[] = {1,1,1,1,23};
		//		int *res = find(begin(a), end(a), 23);
		//		cout<<res==end(a)?"No find":"Find"<<endl;
	}
	{
		ostringstream ostr;
		ostr<<"hello";
		insert(ostr, 123);
		cout<<ostr.str()<<endl;
		//				ostr..clear();	//ss.clear(); //实际上，它并不清空任何内容，它只是重置了流的状态标志而已！
		//				cout<<ostr.str()<<endl;
		ostr.str("");	//ss.clear(); //清空


	}
	//	puts("-------------------------------------");
	{
		//		char c[]={'1','f'};
		//		string s(c,3);	// s[2] is unfixed
		//		cout<<s<<" "<<s.size()<<" "<<s[s.size()]<<endl;	//s.size = 3
		//
		//		s.insert(s.size(), 5, '!');
		//		cout<<s<<endl;
		//
		////		s= to_string(12);	// error
		////		cout<<s<<endl;
	}
	//	cout<<"---------------"<<endl;
	//	{
	//				TestForReturnConst t;
	//				vector<int> v = t.getV();
	//				cout<<v.empty()<<endl;	// put: 1
	//				v.push_back(12);
	//				cout<<v.at(0)<<endl;		// put: 12
	//	}
	//	cout<<"============================="<<endl;
	{
		//		int i = 23;
		//		void *v = &i;
		//		char *c = "fs";
		//		void *v1 =c;
		//		char c1= 'v';
		//		void *v2 = &c1;
		//		printf("%d,%d,%d\n",get_int_from_void(v), get_int_from_void(c), get_int_from_void(v2));//put: 23,620786534,6006
	}
	//	cout<<"============================="<<endl;
	{
		//		char *t = "s123";
		//		cout<<atoi(t)<<endl;	// put 0
	}
	{
		//		char *t = "12s3";
		//		cout<<atoi(t)<<endl;	// put 12
	}
	{
		//		// class constructor test
		//		FlyBird *fly_bird = new FlyBird(121);
		//		fly_bird->feed();	// put: a bird
	}

	{
		// the return of constructor
		NoDefault n1 = NoDefault(12);
		//		NoDefault *p_n1 = NoDefault(12);	//错误：不能将‘NoDefault’转换为‘NoDefault*’，在 initialization 中
		NoDefault *p_n2 = new NoDefault(12);
		p_n2->print_mem();
	}

	{
		// default constructor test
		C c;
		c.print_mem();

		//		vector<NoDefault> vec(10);	// 错误：对‘NoDefault::NoDefault()’的调用没有匹配的函数
		vector<C> vec(10);
	}
	{
		//		int i11= 23;
		//		float f11 = 23.345;
		//		cout<< (i11<f11) <<endl;	//put: 1
	}

	{
		//		char *ei = "0x10";
		//		int eiToten = atoi(ei);
		//		cout<<"Ten :" << eiToten<<endl;	//put: 0
	}

	// for c++11
	//	auto au = "wef"+string("wef");
	//
	//	vector<string> vt1{21};
	//	vector<string> vt2{10,"hie"};
	//	for(auto it = vt1.begin(); it != vt1.end(); ++it)
	//		cout<<*it<<"|";
	//	cout<<endl;
	//	for(auto it = vt2.begin(); it != vt2.end(); ++it)
	//		cout<<*it<<"|";
	//	cout<<endl;

	//	int it= 23;
	//	const int ic = 123;
	//	const int &r = ic ;
	//	it = ic;
	{
		int ___t, _SS,_t;
		cout<<___t<<" "<<_SS<<" "<<_t<<" "<<_g<<endl;

		int &copy = _SS;
		//		cout<<copy<<endl;	// the same as _SS

		int &copy1 = ___t;
		cout<<"c1:"<<copy1<<" ";

		copy1 = copy;
		cout<<"c1:"<<copy1<<" ";
		copy1 = 23.23;
		cout<<"c1:"<<copy1<<endl;
	}

	{
		//		int tt;
		//		string sst;
		//		cout<<tt<<"-"<<sst<<"="<<endl;	// put: 4236800-=
	}
	{
		//		int testforc11{235.56};
		//		cout<<testforc11<<endl;	// put: 235
	}
	{
		//		char ch = 21333;
		//		char ch1 = ch %256;
		//		cout<<(ch==ch1)<<"---";	// ch = ch1
		//		cout<<ch<<endl;	// put: U
	}
	/*	{
   unsigned int ui1 = 10,ui2 = 42;
	int i1 = 10, i2 = 42;

	cout<<ui2-ui1<<endl;
	cout<<ui1-ui2<<endl;
	cout<<i2-i1<<endl;
	cout<<i1-i2<<endl;
	cout<<ui1-i1<<endl;
	cout<<ui1-i1<<endl;
	}
	 */
	//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//	int s = 12;
	//	Node *p1 = (Node *)malloc(sizeof(Node));
	//	cout<<p1<<endl;
	//	p1->type = 124678;
	//	Node **p2;
	//	p2 = &p1;
	//	free(*p2);
	//	*p2 = NULL;
	//	cout<<p1<<endl;
	//	if (p1 != NULL)
	//		cout<<p1->type<<endl;
	//	cout<<p2<<endl;

	//	int i;
	//	   for(i=0; i<2; i++){
	//	      fork();
	//	      printf("-");
	//	   }


	/*  序列化 */
	//
	//	valueType vt= t_double;
	//
	//	map<int, string> is;
	//	is.insert(pair<int,string>(1,"123"));
	//	is.insert(pair<int,string>(2,"234"));
	//	int xx = 12456;
	//	string filename(boost::archive::tmpdir());
	//	filename += "/testfile.txt";
	//	cout<<"old x is: "<<xx<<endl;
	//
	//	std::ofstream ofs(filename.c_str());
	//	boost::archive::text_oarchive oa(ofs);
	//	oa << is;
	//	ofs.close();
	//
	//	valueType newvt;
	//	map<int, string> newis;
	//
	//	std::ifstream ifs(filename.c_str());
	//	boost::archive::text_iarchive ia(ifs);
	//	ia >> newis;
	//	ifs.close();
	//
	//	cout<<"the new is: "<<newis.at(1)<<" "<<newis.at(2)<<endl;

	/**/

	{
		//		int ii;
		//		ii = 10;
		//		printf("i : %d\n",ii);
		//		printf("sizeof(i++) is: %d\n",sizeof(ii++));	// 编译器编译阶段 直接得到值为4，不执行ii++
		//		printf("i : %d\n",ii);
	}
	{
		//	char s[100];
		//	cin>>s;
		//	long double ld = atoll(s);
		//	cout<<ld<<endl;
	}

	{
		// get the max value of long type and unsigned long type
		unsigned long ll = 0;
		ll = ll - 1;
		cout<<ll<<endl;
		cout<<numeric_limits<long double>::max()<<" "<<LONG_MAX<<endl;
		cout<<"int max is: "<<numeric_limits<int>::max()<<endl;
		cout<<numeric_limits<long double>::max_exponent10<<endl;
	}

	{
		//		//获得float的二进制表示
		//		float in = 12.5;
		//		bitset<32> bs(in);
		//		cout<<bs<<endl;	// put: 00000000000000000000000000001100
	}
	{
//				cout<<" "<<f()<<endl;	// f() return 5
//				int x;
//				cout<< (x == (1 && x)) <<endl;	//put: 0
//				cout<<x<<endl;	// put: 4236368
	}

	int i = 3;
	Node *p1= (Node *)malloc(sizeof(Node));
	p1->p = &i;
	p1->type=4;

	newNode(0);newNode(1);newNode(2);newNode(3);
	cout<<pp[0]<<"-"<<pp[1]<<"-"<<pp[2]<<"-"<<pp[3]<<endl;

	cout<<p1->p<<endl;
	Node **p2;
	p2 = &p1;
	free(*p2);
	*p2 = NULL;
	p2 = NULL;
	free(p1);
	cout<<p2<<endl;	// put: 0
	//	cout<<p1->p<<endl;

	{
		//		int sum = 0, iii = 12;
		//		for(int iii = 0; iii != 10; iii++)
		//		{
		//			sum += iii;
		//		}
		//		cout<<iii<<" "<<sum<<endl;	//put: 12 45
	}
	//	{
	//		cout<<"===="<<endl;
	//		char p[10] = "\\\\n";
	//		if(p[0] == '\\')
	//		{
	//			string s(p);
	//			printf("he:%c we%chj",s[0], p[0]);
	//			printf("%s2",p);
	//		}
	//		scanf("%s",p);
	//		printf("%s\n",p);
	//	}

	//	{
	//		int temp;
	//		string t;
	//		while (cin>>temp);	// if input 's', return false and the 's' will be saved in buffer.
	//		cin.clear();
	//		if(cin>>t) cout << "Success !";
	//		else cout << "Error!";
	//		cout<<t<<endl;	// 's'
	//	}
	//	cout<<"---------------"<<endl;
	//	{
	//		int i;
	//		iostream::iostate old_state = cin.rdstate();
	//
	//		// if cin.eof() return true or cin.bad() return true, then cin.fail() also return true
	//		while(cin>>i) cout<<cin.eof()<<"-"<< cin.fail()<<"-"<< cin.bad()<<endl;
	//		cout<<cin.eof()<<"-"<< cin.fail()<<"-"<< cin.bad()<<endl;
	//		cin.clear();
	//		cout<<cin.eof()<<"-"<< cin.fail()<<"-"<< cin.bad()<<endl;
	//
	//		string s;
	//		cin>>s;
	//	}
	cout<<"---------------"<<endl;
	{
		int no_meaning;
		ostream *old_tie = cin.tie();
		cin.tie(&cerr);	//将cin关联cerr，不再关联cout，按理说，读取cin不会刷新cout，貌似 验证失败
		cout<<"sndfisfn";cout<<"sndfisfn";cout<<"sndfisfn";cout<<"sndfisfn";cout<<"sndfisfn";cout<<"sndfisfn";
		cin>>no_meaning;
		cin.tie(old_tie);

		cout<<"sndfisfn";
		cin>>no_meaning;
	}
	cout<<"---------------"<<endl;
	{
		//		vector<int> v;	//default: capacity = 2^n;
		vector<int> v(5);	//capacity = 2^n * 5;
		cout<<"size: "<<v.size()<<"  ";
		cout<<"capacity: "<<v.capacity()<<endl;
		while(v.size()<12)
			v.push_back(11);

		cout<<"size: "<<v.size()<<"  ";
		cout<<"capacity: "<<v.capacity()<<endl;

		v.reserve(44);
		while(v.size()<32)
			v.push_back(111);

		cout<<"size: "<<v.size()<<"  ";
		cout<<"capacity: "<<v.capacity()<<endl;
	}
	cout<<sizeof(void *)<<endl;
	return 0;
}
