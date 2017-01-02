/*************************************
 * build command: 
 * 	g++ -O0 -g3 -std=c++11 -o non_inherit NonInherit.cpp
 * ***********************************/



#include <iostream>
#include <string.h>
using namespace std;


// final class based on c++11
class FinalA final {
	public:
		FinalA(){}
		~FinalA(){}		
};

template<typename T>
class NoInheitBase 
{
  friend T;
private:
  NoInheitBase(){}
  ~NoInheitBase(){}
};

class A : virtual NoInheitBase<A>{
public:
  A(){}
  ~A(){}
};

/*
// ERROR: lear to compile error
class B: public A{
public:
  B(){}	// ERROR: ‘NoInheit<T>::NoInheit() [with T = A]’ is private
};
*/

class NonInstanceClass{
private:
  NonInstanceClass(){}
public:
  ~NonInstanceClass(){}
};

int TestNoInheritClassAndNonInstanceClass() {
  cout<<"hello, world"<<endl;
//    NonInstanceClass nic;	// compile ERROR: construction function is private
//    NonInstanceClass* nic_ptr = new NonInstanceClass;	// ERROR as same as the behind one

  A aa;
  A* a = new A();
//    B b;	// ERROR
  cout<<"bye, world"<<endl;
  return 0;
}

int main() 
{
  return TestNoInheritClassAndNonInstanceClass();
}
