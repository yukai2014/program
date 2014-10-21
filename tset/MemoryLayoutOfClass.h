/*
 * MemoryLayoutOfClass.h
 *
 *  Created on: 2014-9-21
 *      Author: imdb
 */

#ifndef MEMORYLAYOUTOFCLASS_H_
#define MEMORYLAYOUTOFCLASS_H_

#include <iostream>
using namespace std;

//typeof void (*Fun)();

class MemeoryLayoutOfClassDemon
{


private:
	class B
	{
	private:
		//		long lb;
		int ib;
		char cb;
	public:
		B():ib(1000),cb('B'){}
		//		B():lb(100){}
		virtual void f() const {
			cout<<"B::f()"<<endl;
		}
		virtual void Bf() const {
			cout<<"B::Bf()"<<endl;
		}

	};

	class B1: public B
	{
	private:
		//		long lb1;
		int ib1;
		char cb1;
	public:
		B1():ib1(100),cb1('1'){}
		//		B1():lb1(2){}

		virtual void f() const {
			cout<<"B1::f()"<<endl;
		}
		virtual void g() const{
			cout<<"B1::g()"<<endl;
		}
		virtual void h() const{
			cout<<"B2::h()"<<endl;
		}
		virtual void B1f() const {
			cout<<"B1::B1f()"<<endl;
		}
	};

	class B2: public B
	{
	private:
		//		long lb2;
		int ib2;
		char cb2;
	public:
		B2():ib2(10),cb2('2'){}
		//		B2():lb2(3){}
		virtual void f() const {
			cout<<"B2::f()"<<endl;
		}
		virtual void g() const{
			cout<<"B2::g()"<<endl;
		}
		virtual void i() const{
			cout<<"B2::i()"<<endl;
		}
		virtual void B2f() const {
			cout<<"B2::B2f()"<<endl;
		}
	};

	class D:public B1, public B2
	{
	private:
		int id;
		char cd;
		//		long ld;
	public:
		D():id(1),cd('D'){}
		//		D():ld(4){}
		virtual void f() const {
			cout<<"D::f()"<<endl;
		}
		virtual void g() const{
			cout<<"D::g()"<<endl;
		}
		virtual void h() const{
			cout<<"D::h()"<<endl;
		}
		virtual void i() const{
			cout<<"D::i()"<<endl;
		}
		virtual void Df() const {
			cout<<"D::Df()"<<endl;
		}
	};

	public:
	void show(){
		// http://blog.csdn.net/haoel/article/details/3081385
		// 重复继承
		int i;
		typedef void (*Fun)();
		long **p = NULL;
		p = (long**)&d;
		//		for (i = 0; (long)p[0][i] != 1; ++i) {
		//			fun = (Fun)p[0][i];
		//			printf("%p\n", p[0][i]);
		//			cout<<i<<"--";
		//			fun();
		//		}
		cout<<"0: B1 vtable--------"<<endl;
		i = 0;	// i means the count of Bytes
		cout<<"	0: ";(*(Fun)p[i][0])();
		cout<<dec;
		cout<<"	1: ";(*(Fun)p[i][1])();
		cout<<"	2: ";(*(Fun)p[i][2])();
		cout<<"	3: ";(*(Fun)p[i][3])();
		cout<<"	4: ";(*(Fun)p[i][4])();
		cout<<"	5: ";(*(Fun)p[i][5])();
		cout<<"	6: ";(*(Fun)p[i][6])();

		++i;
		cout<<"1: B.ib-->"<<hex<<(((int*)p)+i*2)<<dec<<"-->"<<int(*(((int*)p)+i*2))<<endl;	//ok. 这种方式是将指针p加一个long的字节长度后，用*取出这个地址存的值
		cout<<"1: B.ib-->"<<int(*((int*)(p+i)))<<endl;	// ok
		//		cout<<"7: "<<int(*((int*)(p[1]))B1.cb1--1)<<endl;	// wrong, because p is a pointer actually, rather than a pointer to pointer
		//		cout<<"7: "<<long(p[1])<<endl;				// ok if the member is long. p[1]会直接取出p+1这个地址指向的内存中存的值
		cout<<"2: B.cb-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;		// add a long and a int

		++i;
		cout<<"3: B1.ib1-->"<<int(*(((char*)p)+i*8))<<endl;
		cout<<"4: B1.cb1-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;

		++i;
		cout<<"5: B2 vtable--------"<<endl;
		cout<<"	0: ";(*(Fun)p[i][0])();
		cout<<"	1: ";(*(Fun)p[i][1])();
		cout<<"	2: ";(*(Fun)p[i][2])();
		cout<<"	3: ";(*(Fun)p[i][3])();
		cout<<"	4: ";(*(Fun)p[i][4])();

		++i;
		cout<<"6: B.ib-->"<<int(*((int*)(p+i)))<<endl;
		cout<<"7: B.cb-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;

		++i;
		cout<<"8: B2.ib2-->"<<int(*((int*)(p+i)))<<endl;
		cout<<"9: B2.cb2-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;

		++i;
		cout<<"8: D.id-->"<<int(*((int*)(p+i)))<<endl;
		cout<<"9: D.cd-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;

	}
	private:
	D d;
};

#endif /* MEMORYLAYOUTOFCLASS_H_ */
