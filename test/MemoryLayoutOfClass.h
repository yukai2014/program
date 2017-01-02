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

#define VIRTUAL_INHERIT

template <typename T, typename data_type1, typename data_type2>
char* access_order(data_type1 T::* mem1, data_type2 T::* mem2) ;

//typedef void (*Fun)();

class MemeoryLayoutOfClassDemon
{
//	http://blog.csdn.net/haoel/article/details/3081385

private:
	class B
	{
		//	private:
	  template <typename T, typename data_type1, typename data_type2>
	  friend char* access_order(data_type1 T::* mem1, data_type2 T::* mem2) ;
	public:
		//		long lb;
		int ib;
	private:
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

#ifdef VIRTUAL_INHERIT
	class B1: public virtual B
#endif
#ifndef VIRTUAL_INHERIT
	class B1: public B
#endif
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
#ifdef VIRTUAL_INHERIT
	class B2: public virtual B
#endif
#ifndef VIRTUAL_INHERIT
	class B2: public B
#endif
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
//	  B bb;
//	  cout<<&bb<<"|"<<&(bb.ib)<<endl;
//	  cout<<&B::ib<<endl;
//	  cout<<access_order(&B::ib, &B::ib)<<endl;

		// http://blog.csdn.net/haoel/article/details/3081385

#ifndef VIRTUAL_INHERIT
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
        cout<<" 6: ";(*(Fun)p[i][6])();
		cout<<"	7: "<<(long)p[i][7]<<endl;

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
		cout<<"	5: "<<(long)p[i][5]<<endl;

		++i;
		cout<<"6: B.ib-->"<<int(*((int*)(p+i)))<<endl;
		cout<<"7: B.cb-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;

		++i;
		cout<<"8: B2.ib2-->"<<int(*((int*)(p+i)))<<endl;
		cout<<"9: B2.cb2-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;

		++i;
		cout<<"8: D.id-->"<<int(*((int*)(p+i)))<<endl;
		cout<<"9: D.cd-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;

		//		cout<<d.ib<<endl;
#endif
#ifdef VIRTUAL_INHERIT
		// 多重虚拟继承
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
//				cout<<"	6: ";(*(Fun)p[i][6])();
		cout<<"	6: "<<long(p[i][6])<<endl;
//		cout<<"	7: "<<long(p[i][7])<<endl;

		++i;
		cout<<"1: B1.ib1-->"<<hex<<(((int*)p)+i*2)<<dec<<"-->"<<int(*(((int*)p)+i*2))<<endl;	//ok. 这种方式是将指针p加一个long的字节长度后，用*取出这个地址存的值
		cout<<"1: B1.ib1-->"<<int(*((int*)(p+i)))<<endl;	// ok
		//		cout<<"7: "<<int(*((int*)(p[1]))B1.cb1--1)<<endl;	// wrong, because p is a pointer actually, rather than a pointer to pointer
		//		cout<<"7: "<<long(p[1])<<endl;				// ok if the member is long. p[1]会直接取出p+1这个地址指向的内存中存的值
		cout<<"2: B1.cb1-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;		// add a long and a int

		//		++i;
		//		cout<<"3: B1.ib1-->"<<int(*(((char*)p)+i*8))<<endl;
		//		cout<<"4: B1.cb1-->"<<(*(Fun)p[i][0])<<endl<<endl;

		++i;
		cout<<"3: B2 vtable--------"<<endl;
		cout<<"	0: ";(*(Fun)p[i][0])();
		cout<<"	1: ";(*(Fun)p[i][1])();
		cout<<"	2: ";(*(Fun)p[i][2])();
		cout<<"	3: ";(*(Fun)p[i][3])();
		cout<<"	4: "<<long(p[i][4])<<endl;

		++i;
		cout<<"4: B2.ib2-->"<<int(*((int*)(p+i)))<<endl;
		cout<<"5: B2.cb2-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;

		++i;
		cout<<"D :"<<endl;
		cout<<"6: D.id-->"<<int(*((int*)(p+i)))<<endl;
		cout<<"7: D.cd-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;

		++i;
		cout<<"8: B vtable--------"<<endl;
		cout<<"	0: "<<"something wrong, should be D:f()"<<endl;
//		((Fun)p[i][0])(); // error
		cout<<"	1: ";((Fun)p[i][1])();
		cout<<"	2: "<<Fun(p[i][0])<<endl;	// 值为1，表示还有下一个虚函数表，如果值是0，表示是最后一个虚函数表

		++i;
		cout<<endl<<"11: B.ib-->"<<int(*((int*)(p+i)))<<endl;
		cout<<"9: B.cb-->"<<char(*(((char*)p)+i*8+1*4))<<endl<<endl;
		//		cout<<d.ib<<endl;
#endif

	}
	void test_2_class_pointer(){
/*
        http://blog.csdn.net/littlehedgehog/article/details/5442430
		指针的比较
		   再以上面Bottom类继承关系为例讨论，下面这段代码会打印Equal吗？
		1 Bottom* b = new Bottom();
		2 Right* r = b;
		3
		4 if(r == b)
		5    printf("Equal!/n");
		   先明确下这两个指针实际上是指向不同地址的，r指针实际上在b指针所指地址上偏移8字节，但是，这些C++内部细节不能告诉C++程序员，所以C++编译器在比较r和b时，会把r减去8字节，然后再来比较，所以打印出的值是"Equal".
*/

		typedef void (*Fun)();
		D *pd = &d;
		B1 *pb1 = pd;
		B2 * pb2 = pd;
		// B2作为第二个base class, 确实不一样, B2的指针会加上B1大小的偏移量, 虚拟继承时加上16, 非虚拟继承加上24
		printf("the same object, different class type pointer. D*:%p B1*:%p B2*:%p\n",pd, pb1, pb2);    // D:0x7ffdfb5580b0 B1:0x7ffdfb5580b0 B2:0x7ffdfb5580c0
//		D* pd_fake = dynamic_cast<D*>(new B2());
//		cout<<pd_fake->ib<<endl;    // runtime error
	}
	private:
	D d;
};
template <typename T, typename data_type1, typename data_type2>
char* access_order(data_type1 T::* mem1, data_type2 T::* mem2) {
  if (mem1 < mem2) {
    return "member 1 occurs first";
  } else {
    return "member 2 occurs first";
  }
}
#endif /* MEMORYLAYOUTOFCLASS_H_ */
