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
#include <map>
#include <set>
#include <sstream>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/file.h>
#include <sys/sendfile.h>
#include <aio.h>

#include <xmmintrin.h>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/map.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/archive/tmpdir.hpp>
#include <memory>
#include <new>
#include <ostream>

#include "c++11_features_test.h"
#include "c++11_lambda_test.h"
#include "DataSemiticsTest.h"
#include "MemoryLayoutOfClass.h"
#include "HashFunc.h"
#include "new_test.h"
#include "OverwriteTest.h"
#include "template_recursion.h"
#include "TemplateTest.h"
#include "written_examination.h"
//#include "testsf.cpp"

using namespace std;
//#pragmapack(4)
class kong {
 public:
  virtual void PrintNum() const { cout << "kong" << endl; };  // 8	-->8
  inline void abc() { a = 1; }
  int a;     // 4	-->12
  char b;    // 1	-->16
  double c;  // 8	-->24
  int ba;    // 4	-->32
};

class bird {
 public:
  bird() {
    num = 1;
    cout << "a bird" << endl;
  }
  virtual void PrintNum() {  // 8    -->8
    cout << "bird is " << num << endl;
  }

 public:
  //  double num; // 4    -->16
  int num;
};

/*
 * kongbird:
 *          vtable* ----> 指向kong 的虚函数表  // 8 --- 8
 *          vtable* ----> 指向 bird的虚函数表  // 8 --- 16
 *      ----------------------- 接下来是kong的成员
 *          int a;                                  // 4    -->20
 *          char b;                                 // 1    -->24
 *          double c;                               // 8    -->32
 *          int ba;                                 // 4    -->36
 *      ----------------------- 接下来是bird的成员
 *          int num;                                    // 4 --- 40
 *      ----------------------- 接下来是kongbird的成员
 *          int temp；                               // 4 --- 48
 *
 *  如果改num为double， 则sizeof（kongbird）为56
 */
class kongbird : public bird, public kong {
 private:
  int temp;
  void PrintNum() const { cout << "kb" << endl; }
};

class FlyBird : public bird {
  friend bool feed();

 public:
  //	FlyBird() = default;
  FlyBird(const int init) : test_for_init(init) {}
  /*	FlyBird(){
   new_number = 11;
   //		cout<<num<<endl;
   cout<<new_number<<endl;
   }*/
  bool feed();
  void print() {
    cout << "fly bird num is" << num << endl;
    PrintNum();
  }

 private:
  int new_number;
  const int test_for_init;
  int num;
};

bool FlyBird::feed() {
  new_number = 1;
  return 1;
}

class NoDefault {
 public:
  NoDefault(int i) : ii(i) {
    cout << "this is NoDefault(" << ii << ")" << endl;
  }
  //	NoDefault(){}
  void print_mem() { cout << "the member of NoDefault is :" << ii << endl; }
  void DeleteSelf();

 private:
  int ii;
};

void NoDefault::DeleteSelf() {
  delete this;
  //	cout<<"delete successfully"<<endl;
}

class C {
 public:
  //	C(NoDefault nd = NoDefault(0)):d(nd){}	// OK, this is default
  // constructor
  C() : d(NoDefault(3.5)) {}  // OK, this is also default constructor
  void print_mem() {
    cout << "ok " << endl;
    d.print_mem();
  }

 private:
  NoDefault d;
};

struct Node  //基本节点
    {
  int *p;
  int type;
  char *d;
  Node(int i) : type(i) {}

  friend void operator<<(ostream &os, Node &n) { os << n.type; }

  //	istream &operator >>(istream &is, Node n)
};

bool IsSmaller(const Node &a, const Node &b) { return a.type < b.type; }

void operator>>(istream &is, Node &n) {
  //		istream is;*(n.p)>>
  is >> n.type;
}

Node *pp[10];

Node *newNode(int i) {
  Node *p1 = (Node *)malloc(sizeof(Node));
  p1->type = 1;
  pp[i] = p1;
  return p1;
};

int xx = 5;
int f() {
  int xx = 3;
  {
    extern int xx;
    cout << xx << endl;
    return xx;
  }
}
enum valueType { t_int, t_float, t_double };

class ClassForSerialization {
 public:
  ClassForSerialization(int a, int b) : num(a), k(b) {}

 public:
  void Print() { cout << num << " " << k << endl; }

 private:
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar &num &k;
  }

 public:
  void SaveFile(const char *filename) {
    std::ofstream ofs(filename);
    boost::archive::text_oarchive oa(ofs);
    oa << *this;
  }

  void RestoreSth(const char *filename) {
    std::ifstream ifs(filename);
    boost::archive::text_iarchive ia(ifs);
    ia >> *this;
  }

 public:
  int num;

 private:
  int k;
};

template <class T>
void SaveSth(const T t, const char *filename) {
  std::ofstream ofs(filename);
  boost::archive::text_oarchive oa(ofs);
  oa << t;
}

template <class T>
void RestoreSth(const T t, const char *filename) {
  std::ifstream ifs(filename);
  boost::archive::text_iarchive ia(ifs);
  ia >> t;
}

void SaveSth(const int &x, const char *filename) {
  std::ofstream ofs(filename);
  boost::archive::text_oarchive oa(ofs);
  oa << x;
}

void RestoreSth(int &x, const char *filename) {
  std::ifstream ifs(filename);
  boost::archive::text_iarchive ia(ifs);
  ia >> x;
}

// test the serialization of enum type
void SaveSth(const valueType &x, const char *filename) {
  std::ofstream ofs(filename);
  boost::archive::text_oarchive oa(ofs);
  oa << x;
}

void RestoreSth(valueType &x, const char *filename) {
  std::ifstream ifs(filename);
  boost::archive::text_iarchive ia(ifs);
  ia >> x;
}

int _g;

int get_int_from_void(void *arg) { return *(int *)arg; }

class TestForReturnConst {
 public:
  const vector<int> &getV() const { return V; }

 private:
  vector<int> V;
};

void insert(ostringstream &ostr, int i) { ostr << i; }

const string file_name = "a.txt";

void *WriteFile(void *arg) {
  char s = *(char *)arg;
  ofstream ofs("a.txt", ofstream::app);

  int i = 10000;
  while (--i) {
    ofs << s;
  }
  return (void *)0;
}
//
// char *get() {
//	char p[]="jelelo";
//	return p;
//}

class CC {
 public:
  void print_mem() { cout << "p[[" << endl; }
};

void aaa(vector<CC *> &ccc) {
  CC c;
  CC *p = new CC();
  cout << "CC c：   " << &c << endl;
  cout << "new CC： " << p << endl;
  ccc.push_back(&c);
  ccc.push_back(p);
}

#define OutputFormatInfo(a)                                                  \
  {                                                                          \
    struct timeval tv;                                                       \
    struct tm *tm;                                                           \
    gettimeofday(&tv, NULL);                                                 \
    tm = localtime(&tv.tv_sec);                                              \
    printf("[%d-%d-%d %d:%d:%d.%ld]	INFO	%s:%d ", tm->tm_year + 1900, \
           tm->tm_mon, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec,     \
           tv.tv_usec, __FILE__, __LINE__);                                  \
    cout << a << endl;                                                       \
  }

void *CloseFd(void *para) {
  int fd = *((int *)para);
  if (-1 == close(fd)) {
    perror("in child thread: close.");
  } else {
    cout << "close ok in child thread" << endl;
  }
  return NULL;
}

unsigned int HashA(const std::string &s) {
  unsigned int key = 0;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    key += s[i] * (unsigned)pow(31, n - 1 - i);
  }
  return key;
}

/**
 *  FNV-1a hash:
 * http://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash
 */
unsigned int HashB(const std::string &s) {
  unsigned int hash = 2166136261U;
  for (int i = 0; i < s.length(); ++i) {
    hash ^= (unsigned)s[i];
    hash +=
        (hash << 1) + (hash << 4) + (hash << 7) + (hash << 8) + (hash << 24);
  }
  return hash;
}

/**
 * Jenkins hash function:
 * http://en.wikipedia.org/wiki/Jenkins_hash_function
 */
unsigned int HashC(const std::string &s) {
  unsigned int hash = 0, i = 0;
  unsigned int len = s.length();
  for (i = 0; i < len; ++i) {
    hash += s[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);
  return hash;
}

#define DEBUG

#define LOGINFO                                                                \
  struct timeval tv;                                                           \
  struct tm *tm;                                                               \
  gettimeofday(&tv, NULL);                                                     \
  tm = localtime(&tv.tv_sec);                                                  \
  printf("[%d-%d-%d %d:%d:%d.%ld]	INFO	%s:%d	", tm->tm_year + 1900, \
         tm->tm_mon, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec,         \
         tv.tv_usec, __FILE__, __LINE__);

#ifdef DEBUG
#define LOG(format, ...) \
  { LOGINFO printf(format, ##__VA_ARGS__); }

#define LOGS(s) \
  { LOGINFO cout << s << endl; }
#endif

#define ELOG(format, ...) \
  { LOGINFO printf(format, ##__VA_ARGS__); }

#define ELOGS(s) \
  { LOGINFO cout << s << endl; }

char *ptr = new char;
int sz = 7;
char *ptr_next_size() { return (ptr + sz - sizeof(int)); }
char *ptr_next_ptr() { return (ptr_next_size() - 28); }

#include "LockFromBoostTest.h"
pthread_mutex_t lock1;

void DirectLock() {
  static int idl = 0;
  pthread_mutex_lock(&lock1);
  idl++;
  //			cout<<idl;
  pthread_mutex_unlock(&lock1);
}

void GuardLock() {
  static int igl = 0;
  guard<pthread_mutex_t> g(lock1);
  igl++;
  //			cout<<igl;
}
double get_current_ms() {
  timeval t_start;
  gettimeofday(&t_start, NULL);
  printf("%ld %lf\n", t_start.tv_sec, t_start.tv_usec * 1.0f / 1000);
  return t_start.tv_sec * 1000.0 + t_start.tv_usec / 1000.0;
}

/*
 * @param start: the start time
 * @return : the elapsed time(ms) from start
 */
double GetElapsedTime(double start) {
  timeval t_end;
  gettimeofday(&t_end, NULL);
  printf("%ld %lf\n", t_end.tv_sec, t_end.tv_usec * 1.0 / 1000);
  return (t_end.tv_sec / 1000 + 1.0 * t_end.tv_usec / 1000) - start;
}
void OutOfMemory() {
  cerr << "memory exhausted after " << endl;
  exit(1);
}

#define DF(N) \
  void N() { cout << "function" << #N << "called .." << endl; }

DF(a);
DF(b);
DF(c);
DF(d);

#define CLASS(ID) \
  class ID {      \
   public:        \
    ID(int) {}    \
  };

CLASS(MEMBER1);
CLASS(MEMBER2);
CLASS(MEMBER3);

template <typename T>
class Queue {
 public:
  Queue(int length) : max_length_(length), cur_(0) {
    assert(max_length_ > 0);
    data_ = new T[max_length_];
  }
  ~Queue() { delete[] data_; }
  void PushBack(const T &t) {
    assert(Full() == false);
    data_[cur_++] = t;
  }
  T Front() { return data_[0]; }
  void Pop() {
    assert(Empty() == false);
    for (int i = 0; i < cur_ - 1; ++i) {
      data_[i] = data_[i + 1];
    }
    --cur_;
  }
  int Size() { return cur_; }
  bool Empty() { return cur_ == 0; }
  bool Full() { return cur_ == max_length_; }
  T &operator[](int index) { return data_[index]; }
  inline int Length() { return max_length_; }

 private:
  T *data_;
  int max_length_;
  int cur_;
};

class TestTemplateClassAsMember {
 public:
  TestTemplateClassAsMember() { q = new Queue<int>(10); }
  void Print() { cout << q->Length() << endl; }

 private:
  Queue<int> *q;
};

/* get the total number of cores */
static int getNumberOfCpus() { return sysconf(_SC_NPROCESSORS_CONF); }

/* get the id of the cpu running the current thread */
static int getCurrentCpuAffility() {
  cpu_set_t mask;
  if (sched_getaffinity(0, sizeof(mask), &mask) < 0) {
    cout << errno << "  " << strerror(errno) << endl;
    return -1;
  }
  for (int i = 0; i < getNumberOfCpus(); i++) {
    if (CPU_ISSET(i, &mask)) {
      return i;
    }
  }
  return -1;
}
/*
void elog(const char* format, ...) {
  const int messege_length = 10000;
  static char p[messege_length];
  fprintf(stderr, "Error: ");
  va_list arg;
  va_start(arg, format);
//  vfprintf(stderr,format,arg);
  vsnprintf(p, messege_length, format, arg);
  va_end(arg);
  cerr << p << endl;
}
*/
struct unpacked_struct {
  char c;
  int i;
  ~unpacked_struct() { cout << i << "---it is unpacked_struct" << endl; }
};

struct packed_struct_1 {
  char c;
  int i;
} __attribute((__packed__));

struct packed_struct {
  char c;
  int i;
  struct unpacked_struct s;
} __attribute__((__packed__));

struct all_packed_struct {
  char c;
  int i;
  struct packed_struct_1 s;
} __attribute__((__packed__));

static __attribute__((constructor(99))) void hello100() {
  cout << "hello99" << endl;
}
static __attribute__((constructor(01))) void hello101() {
  cout << "hello01" << endl;
}
static __attribute__((constructor(102))) void hello102() {
  cout << "hello102" << endl;
}
static __attribute__((destructor(100))) void world100() {
  cout << "world100" << endl;
}
static __attribute__((destructor(101))) void world101() {
  cout << "world101" << endl;
}
static __attribute__((destructor(00))) void world102() {
  cout << "world00" << endl;
}
// unpacked_struct ssss;
#define GETCURRENTTIME(t) \
  timeval t;              \
  gettimeofday(&t, NULL);

/*
 * @param start: the timeval of start time
 * @return : the elapsed time(ms) from start, accurate to us!
 */
static double GetElapsedTime(struct timeval start) {
  timeval end;
  gettimeofday(&end, NULL);
  return (end.tv_usec - start.tv_usec) / 1000.0 +
         (end.tv_sec - start.tv_sec) * 1000.0;
}

// compare performance of function call and virtual function call
void Inc(long &i) throw() { i = i * 2 ; i = i + 5; i = i%6;}
class Base {
 public:
  ~Base() {
    Print();
  }
  virtual void Inc(int &i) { i = i + 2; i = i + 3; }
  virtual void Print(){cout<<"Base"<<endl;}
 private:
  int i1;
  int i2;
};

class Derived : public Base {
 public:
  Derived() {
//    void* temp = new char[100000000000000];   // throw exception, call ~Base()
  }
  ~Derived() {
    Print();
  }
  virtual void Inc(long &i) { i = i + 3;i = i + 3; }
  virtual void Print(){cout<<"Derived"<<endl;}
 private:
  char c;
  int i;
};

class DefaultValueClass {
 public:
  explicit DefaultValueClass(int i) { i_ = i; }
  void Print() { std::cout << i_ << " " << j_ << std::endl; }

 private:
  int i_ = -3;
  int j_ = -4;
};

void drawper(int iFirst, int iSecnd, char *spOut) {
  static int iCrlmm = 0;
  int iPer = iFirst * 100 / iSecnd;

  if (iFirst == iSecnd)
    sprintf(spOut, "[ %d%]\n", iPer);
  else if (iCrlmm == 0)
    sprintf(spOut, "[| %d%]\r", iPer);
  else if (iCrlmm == 1)
    sprintf(spOut, "[/ %d%]\r", iPer);
  else if (iCrlmm == 2)
    sprintf(spOut, "[- %d%]\r", iPer);
  else if (iCrlmm == 3)
    sprintf(spOut, "[\\ %d%]\r", iPer);

  iCrlmm = (++iCrlmm) % 3;
}
void proessview() {
  char szStr[255] = "=======================";
  int iStrLen = strlen(szStr);
  char cTmp = '>';
  char szOut[10] = "";
  int i = 0;
  for (i = 0; i <= iStrLen; i++) {
    szStr[i] = cTmp;

    memset(szOut, 0, sizeof(szOut));
    drawper(i, iStrLen, szOut);

    memcpy(szStr + iStrLen, szOut, strlen(szOut));
    fseek(stdout, 0, SEEK_SET);
    fprintf(stdout, szStr);
    fflush(stdout);

    usleep(500000);
  }
}
// void sdfsfsfsfsdfs(const string &s) { s = s + s; }  // compile error
// void Change(const string &s) { s = "23423" + s; }  // compile error

class TestCase {
 public:
  explicit TestCase(char *a = NULL) {}
  inline virtual void f() {}

 protected:
  int i = 10;

 public:
  int j = 3;
};
//  error: ‘void operator=(TestCase&, TestCase&)’ must be a nonstatic member
//  function !!!!
// void operator=(TestCase &a, TestCase &b) { a = b; }

class ProtectedChildTest : protected TestCase {
 public:
  void Print() {
    cout << "the protected member of Base class protected derived is :" << i
         << endl;  // succeed
  }
};

template <typename T>
class STLGuardWithRetCode {
 public:
  STLGuardWithRetCode(T &t, int &ret) : t_(t), ret_(ret) {}
  ~STLGuardWithRetCode() {
    if (0 != ret_) {
      cout << "size of t_ :" << t_.size() << endl;
      for (auto it : t_) delete (it);
      t_.clear();
    } else {
      cout << "do nothing" << endl;
    }
  }

 private:
  T &t_;
  int &ret_;
};

void PrintLength(char *a, char b[]) {
  cout << sizeof(a) << " " << sizeof(b) << endl;
}

void temp_lambda(shared_ptr<int> &p) { cout << p << endl; }

// shared_ptr<unpacked_struct> global_p;

unpacked_struct *global_us = new unpacked_struct();

/// the initialize order is depend on the declared order
class ClassIncludeClass {
 public:
  ClassIncludeClass() : nd(b.num) { i = 1; }
  int i;
  bird b;        // call bird's constructor
  NoDefault nd;  // if bird is declared before NoDefault, print NoDefault(1).
                 // the '1' is from initialized bird
                 // else print NoDefault(0). the 0 is from non-initialized bird
};

class NoDefault1 {
private:
  int px, py;
 public:
  int i = -12;
  void *a = nullptr;
public:
  int x, y, z;
private:
  int pz;
public:
  void PrintAddressOfMember(){
    cout<< &NoDefault1::x<<"||"<<&NoDefault1::y<<"||"<<&NoDefault1::z<<"||"<<endl;  // 1||1||1||
    // place data member in memory depend on these declared order
    printf("%p||%p||%p||%p||%p||%p\n", &NoDefault1::x, &NoDefault1::y, &NoDefault1::z, &NoDefault1::px, &NoDefault1::py, &NoDefault1::pz);   // 0x18||0x1c||0x20||(nil)||0x4||0x24

    int NoDefault1::*p1 = 0;
    int NoDefault1::*p2 = &NoDefault1::px;
    printf("%p||%p\n", p1, p2); // 0xffffffffffffffff||(nil)
    if (p1 == p2) {
      cout<<" p1& p2 contain the same value, so they must address the same member"<<endl;
    }
  }
};
int endlessfunction(int i){
  int a[400000];
  cout<<a[300000]<<endl;
  cout<<i<<endl;
  return endlessfunction((i+1)%1000);
}

int main() {
  cout<<"hello, world"<<endl;
  {
    return endlessfunction(0);
  }
  {
    char* pp = new char[sizeof(Base)];
    Base* bs = new (pp) Base();
//    delete (pp, bs);    // called by placement new operator by compiler, not by user

    cout<<"------------"<<(void*)pp<<endl;
    bs = new (pp) Base();
    cout<<"------------"<<(void*)pp<<endl;
    //    delete (pp, bs);    // called by placement new operator by compiler, not by user
    free( pp);

    Base b;
    b.~Base();
    new (&b) Derived();
    b.Print();  // "Base", still call Base::Print()
    cout<<"----------------------------------"<<endl;
    Base* p = new Derived[10];
    delete[] p; // even Derived is bigger than Base, print 10 "Base" successfully.
                // segmentation fault which I expect doesn't occur --- <<Inside C++ object model>> P262
//    return 0;
  }
  {
    // Plain OI' Data ----<Inside the c++ object model> P196
    // the appearance doesn't occur :(
    typedef struct {
      float x, y, z;
    } Point ;
    Point local;
    Point* heap = new Point;
    *heap = local;

    cout<<"heap x:"<<heap->x<<", heap y:"<<heap->y<<", heap z:"<<heap->z<<endl; // heap x:0, heap y:0, heap z:-3.46112e+24
//    return 0;
  }

  {
    // print the order of every data member in memory
    NoDefault1 nd1; nd1.PrintAddressOfMember();
  }
  { TestDataSemitics(); }
  {
    MemeoryLayoutOfClassDemon demon;
    demon.show();
    demon.test_2_class_pointer();
//    cout<<" ok , in deap:"<<endl;
//    MemeoryLayoutOfClassDemon* p = new MemeoryLayoutOfClassDemon();
//    p->show();
                  return 0;
  }
  {
    // copy on write
    string a1 = "wrwr";
    string b = a1;
    cout << (void *)a1.c_str() << "," << (void *)b.c_str() << endl; // 0x247b588,0x247b588
    b[1] = '1';
    cout << (void *)a1.c_str() << "," << (void *)b.c_str() << endl; // 0x247b588,0x247b5b8
  }
  {
    // test initialization order
    NoDefault1 nd1;
    cout << nd1.i << " " << nd1.a << endl;
    ClassIncludeClass *fb = new ClassIncludeClass();
    delete fb;
  }
  {
    // implement of memcpy()
    GETCURRENTTIME(start);
    char a[] =
        "sfnwefnslnsnfsfddegfherhhhhhhh253t243t234tg24ty45y45hgery45y45y345hyg3"
        "4y47y536y34t23tttttttttttttttttttttttttttttr23tr23t34y5 "
        "6ie47nu8e6yws5yw45y5vq4tr3wct34vy5y4wrfesvt54wy4w5ygerlfns";
    cout << (void *)a << endl;
    for (int i = 0; i < 10; ++i) cout << *(long *)(a + i) << " ";
    cout << endl;
    int repeat = 100;
    while (repeat--) {
      // implement of memcpy
      char *b = new char[300]{0};
      if ((uint64_t)b % 8 != 0) {
        cerr << "not this address  " << (void *)b << endl;
      }
      //      b++;
      //      if ((uint64_t)b % 8 == 0) {
      //        cerr << "not this address  " << (void *)b << endl;
      //      }
//            cout << (void *)b << " " << sizeof(a) << endl;

      int len = sizeof(a);
      for (int i = 0; i < len / static_cast<int>(sizeof(uint64_t)); ++i) {
        *(uint64_t *)(b + i * sizeof(uint64_t)) =
            *(uint64_t *)(a + i * sizeof(uint64_t));
      }
      for (int i = len / sizeof(uint64_t) * sizeof(uint64_t); i < len; ++i) {
        *(char *)(b + i) = *(char *)(a + i);
      }
      if (0 != strcmp(a, b)) {
        cout << a << endl;
        cout << b << endl;
        cerr << "error" << endl;
        break;
      }
      delete[] b;
    }
    cout << GetElapsedTime(start) << "ms" << endl;
//    return 0;
  }
  {
    // bit endian or little endian
    union Union {
      int a;
      char c;
    };
    Union u;
    u.a = 65;
    cout << u.c << endl;  // A --> little endian
  }
  {
    int i = -1;
    const char *p = to_string(i).c_str();
    cout << (void *)p << "===" << p << endl;    // 0x1009588===-1
  }
  {
    void *a = malloc(0);
    int *b = (int *)malloc(0);
    cout << a << "--" << b << "--" << (b == NULL) << "--" << *b << endl;    // 0x10095a0--0x10095c0--0--858944564
  }
  {
    /// test shared_ptr in multi-threading. Add into notebook
    //    global_p(t);
    //    delete t;

    cout << "========" << endl;
    unpacked_struct *p = new unpacked_struct();
    p->i = 512314;
    shared_ptr<unpacked_struct> p1(p);
    shared_ptr<unpacked_struct> p2(p1);
    shared_ptr<unpacked_struct> p3(p1);
    shared_ptr<unpacked_struct> p4(p1);
    shared_ptr<unpacked_struct> p5(p1);

    thread th1([&]() {
      unpacked_struct *t = new unpacked_struct();
      t->i = 1;
      //      global_p.reset(t);
      //      cout << (void *)(&global_p) << " 1 " << global_p->i << endl;
      //      shared_ptr<unpacked_struct> p1(global_us);
      p1.reset(t);
      cout << (void *)(&p1) << " 1 " << p1->i << endl;
    });
    thread th2([&]() {
      unpacked_struct *t = new unpacked_struct();
      t->i = 2;
      //      global_p.reset(t);
      //      cout << (void *)(&global_p) << " 2 " << global_p->i << endl;
      p2.reset(t);
      //      shared_ptr<unpacked_struct> p2(global_us);
      cout << (void *)(&p2) << " 2 " << p2->i << endl;
    });
    thread th3([&]() {
      unpacked_struct *t = new unpacked_struct();
      t->i = 3;
      //      global_p.reset(t);
      //      cout << (void *)(&global_p) << " 3 " << global_p->i << endl;
      p3.reset(t);
      //      shared_ptr<unpacked_struct> p3(global_us);
      cout << (void *)(&p3) << " 3 " << p3->i << endl;
    });
    thread th4([&]() {
      unpacked_struct *t = new unpacked_struct();
      t->i = 4;
      //      global_p.reset(t);
      //      cout << (void *)(&global_p) << " 3 " << global_p->i << endl;
      p4.reset(t);
      //      shared_ptr<unpacked_struct> p4(global_us);
      cout << (void *)(&p4) << " 4 " << p4->i << endl;
    });
    thread th5([&]() {
      unpacked_struct *t = new unpacked_struct();
      t->i = 5;
      //      global_p.reset(t);
      //      cout << (void *)(&global_p) << " 3 " << global_p->i << endl;
      p5.reset(t);
      //      shared_ptr<unpacked_struct> p5(global_us);
      cout << (void *)(&p5) << " 5 " << p5->i << endl;
    });

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    cout << endl << "========" << endl;

    //    return 0;
  }
  {
    string message =
        "LINEITEM,|,\n,"
        "1|155190|7706|1|17|21168.23|0.04|0.02|N|O|1996-03-13|1996-\n|"
        "wef3r2tfdfds\n|"
        "h29rbbfvbf|\n|";
    size_t pos = message.find(',', 0);
    string table_name_ = message.substr(0, pos);
    pos++;
    size_t next_pos = message.find(',', pos);
    string col_sep_ = message.substr(pos, next_pos - pos);

    pos = next_pos + 1;
    next_pos = message.find(',', pos);
    string row_sep_ = message.substr(pos, next_pos - pos);
    cout << "table name:" << table_name_ << ", column separator:" << col_sep_
         << ", row separator:" << row_sep_;
    cout << sizeof(uint64_t) << endl;

    pos = next_pos + 1;
    while (string::npos != (next_pos = message.find('\n', pos))) {
      cout << (message.substr(pos, next_pos - pos)) << endl;
      pos = next_pos + 2;
    }
    return 0;
  }
  {
    vector<vector<vector<int>>> a(unsigned(3));
    cout << "sf" << endl;
    a[0].resize(13);
    a[1].resize(23);
    a[2].resize(23);
    puts("sfwe");

    a[1][2].push_back(12);
    puts("sfwe");
    a[1][2].push_back(22);
    puts("sfwe");
    cout << a.size() << endl;
    cout << a[0].size() << endl;
    cout << a[1][2][1] << endl;
    //    cout << a[1][23][0] << endl; // error
    puts("ok");
    return 0;
  }
  {
    cout << sum_n<12>::v << endl;
    cout << sum_n<123>::v << endl;
    // error: template instantiation depth exceeds maximum of 900
    //    cout << sum_n<1024>::v << endl;
  }
  //  {
  //    char a[] = "hello";
  //    char *b = "hello";
  //
  //    cout << sizeof(a) << " " << sizeof(b) << endl;  // 6 8
  //    PrintLength(a, a);                              // 8 8
  //    PrintLength(b, b);                              // 8 8
  //  }
  //  {
  //    vector<int *> a;
  //    a.push_back(new int(32));
  //    a.push_back(new int(3));
  //    a.push_back(new int(132));
  //    a.push_back(new int(2));
  //    sort(a.begin(), a.end());
  //    int ret = 01;
  //
  //    STLGuardWithRetCode<vector<int *>> guard(a, ret); // works well
  //
  //    ret = 0;
  //  }
  //  {
  //    vector<int *> a;
  //    a.push_back(new int(32));
  //    a.push_back(new int(3));
  //    a.push_back(new int(132));
  //    a.push_back(new int(2));
  //    sort(a.begin(), a.end());
  //    int ret = 0;
  //
  //    STLGuardWithRetCode<vector<int *>> guard(a, ret);
  //
  //    ret = 1;
  //    return 0;
  //  }
  {
    ProtectedChildTest pt;
    pt.Print();
    //    cout << "the public member of Base class protected derived is :" <<
    //    pt.j << endl;  // error: ‘int TestCase::j’ is inaccessible
  }
  { WrittenTest(); }
  {
    int arr[5] = {2, 4, 6};
    int *p = arr;
    cout << p[2] << " " << arr[2] << " " << *(p + 2) << " " << *(p + *arr)
         << endl;
    //    terminate();
  }
  {
    // get the size of buffer for printf-----1024bytes
    //    int i = 0x61;
    //    while (1) {
    //      printf("%c", i);
    //      i++;
    //      i = (i - 0x61) % 26 + 0x61;
    //      usleep(1000);
    //    }
    //
    //    return 0;
  }
  {
    TestOverwrite();
    //    return 0;
  }
  { TestNewDelete(); }
  { TestLambda(); }
  {
    string s = "hello";
    //    Change(s);
    //    cout << s << std::endl;
    char a[] = "hello";
    printf(
        "\e[0;31m"
        "%s\033[0m\n",
        s.c_str());
    printf("sizeof is %d\n", sizeof(a));
    //    return 0;
  }
  {
    MemeoryLayoutOfClassDemon mc;
    mc.show();
    //    return 0;
  }
  {
    bird *fb = new FlyBird(1);
    cout << typeid(*fb).name() << endl;  // 7FlyBird

    fb = new kongbird();
    cout << typeid(*fb).name() << endl;  // 8kongbird
                                         //    return 0;
  }
  {
    //    string s = "^M";
    //    cout << "|" << '^M' << "|" << endl;
    //    ifstream ifs("/home/imdb/rawData/poc-raw-data/SSE_demo/field.txt");
    //    while (getline(ifs, s, '\n')) {
    //      s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());
    //      cout << s.length() << "|" << s << "|" << (s == "\r") << "|"
    //           << s.at(s.length() - 3) << endl;
    //    }
    //    return 0;
  }
  {
    //    proessview();
    //    return 0;
    cout << setprecision(20) << get_current_ms() << std::endl;
    //    return 0;
  }
  //  {
  //    static char *load_output_info[7] = {"Loading         \r", "Loading.\r",
  //                                        "Loading..\r", "Loading...\r",
  //                                        "Loading....\r", "Loading.....\r",
  //                                        "Loading......\r"};
  //    int i = -1;
  //    while (1) {
  //      cout << load_output_info[i = (++i) % 7] << flush;
  //      sleep(1);
  //    }
  //  }

  {
    //    DefaultValueClass a;
    //    a.Print();
    DefaultValueClass b(1);
    b.Print();
    //    return 0;
  }
  {
    void *p = malloc(0);
    cout << p << endl;
    *(int *)p = 1234235;
    cout << *(int *)p << endl;
    p = malloc(10);
    cout << p << endl;
    //    return 0;
  }
  {
    string a = "\n";
    cout << a.length() << endl;  // 1

    string::size_type prev_pos = 0;  // same as unsigned long
    string::size_type pos = 0;
    string s = "fwef|23rf|23fr|";
    for (int i = 0; i < 5; ++i) {
      pos = s.find("|", prev_pos);

      string text_column = s.substr(prev_pos, pos - prev_pos);
      prev_pos = pos + 1;  // when pos is npos which is ULONG_MAX, prev_pos will
                           // be assigned as 0
      cout << pos << " " << (pos == string::npos) << " "
           << "prev pos:" << prev_pos << "  " << text_column << endl;
    }
    //    return 0;
  }
  {
    double total_check_string_time_ = 0;
    GETCURRENTTIME(start);
    for (int i = 0; i < 1500000; ++i) {
      GETCURRENTTIME(check_string_time);
      total_check_string_time_ += GetElapsedTime(check_string_time);
    }
    cout << "time:" << GetElapsedTime(start) / 1000 << std::endl;  // 0.098507


    //    return 0;
  }
  {
    bird *b1 = new FlyBird(1);
    bird *b2 = new kongbird();
    cout << typeid(*b1).name() << " " << typeid(*b2).name() << endl;
    //    return 0;
  }
  //  {
  //    cout << "sfdfs" << endl;
  //    void *p = NULL;
  //    p = 0x0;
  //    cout << *(int *)p << endl;  // segmentation fault
  //    cout << "sfdfs" << endl;
  //    return 0;
  //  }
  {
    cout << "unpacked struct :" << sizeof(unpacked_struct) << endl;      // 8
    cout << "packed struct :" << sizeof(packed_struct) << endl;          // 16
    cout << "all packed struct :" << sizeof(all_packed_struct) << endl;  // 10
  }
  {
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    auto it = find(temp.begin(), temp.end(), 2);
    cout << *it << endl;
    //    return 0;
  }
  {
    FlyBird *b = new FlyBird(1);
    b->feed();
  }
  {
    elog("nihao %s", "yukai");
    //    return 0;
  }

  { class CC { };
    CC c();  // ATTENTION! It is a function declaretion named c, returning CC
             // object!
    //    cout << static_cast<void*>(&c) << endl; // invalid static_cast from
    //    type ‘main()::CC (*)()’ to type ‘void*’
    CC c1;
    cout << static_cast<void *>(&c1) << endl;
  }
  {
    TestNewFeature();
    //    return 0;
  }
  {
    // test size of chinese char
    string a = "你好阿";
    cout << a.size() << endl;  // 9    --->  an chinese char equal three bytes
                               //    return true;
  }
  {
    double a = 500, b = .1;
    int k = (a / b);
    cout << k << endl;
    float aa = 0.12345678910121416;
    cout << aa << endl;
  }
  {
    ClassForSerialization b(1, 2);
    b.SaveFile("test.dat");
    b.Print();
    b.num = 12;
    b.RestoreSth("test.dat");
    b.Print();
    //    return 0;
  }
  { cout << getNumberOfCpus() << " " << getCurrentCpuAffility() << endl; }

  {
    int i = 3;
    cout << i++ << " " << i << endl;  // 3 4
  }
  {
    // Test template class
    TemplateTestClass<int> t;
    t.Print();
    //		return 0;
  }
  {
    Queue<int> q(3);
    cout << q.Empty() << "\t" << q.Full() << "\t" << q.Size() << endl;
    q.PushBack(1);
    q.PushBack(2);
    q.PushBack(3);
    int temp = q.Front();
    cout << temp << endl;
    cout << q.Empty() << "\t" << q.Full() << "\t" << q.Size() << endl;
    q.Pop();
    q.Pop();
    q.Pop();
    cout << q.Empty() << "\t" << q.Full() << "\t" << q.Size() << endl;
    q.PushBack(4);
    for (int i = 0; i < q.Size(); ++i) {
      cout << q[i] << "\t";
    }
    cout << endl;

    TestTemplateClassAsMember a;
    a.Print();
    //		return 0;
  }

  {  // 一个类对象作为另一个类的成员变量
    class A {
     public:
      A(int i) : m(i) { cout << "A():" << m << endl; }
      int m;
    };
    class B {
     public:
      B(int i) : a(i) { cout << "B()" << endl; }

     private:
      A a;
    };

    new B(1);  // A()
               // B()
               //    return 0;
  }
  {
    int i = 0x10000;
    void *p = &i;
    cout << *(bool *)p << endl;                    // 0
    cout << (bool)i << endl;                       // 1
    cout << ((*((int *)p)) == 0 ? 0 : 1) << endl;  // it is right
    cout << "finished" << endl;
    //    return 0;
  }
  /*	{
   set_new_handler(OutOfMemory);
   while ( 1 )
   {
   new int[500000000L];	// when no memory , OutOfMemory is call
   cout << "Allocating 500000000 ints." << endl;
   }
   return 0;
   }
   */
  {
    struct AStructWithOneFunction {
      void f();
    };
    struct AStructWithOneVirtualFunction {
      virtual ~AStructWithOneVirtualFunction() {}
    };
    struct AStructWithTwoVirtualFunction {
      virtual void F(){};
      virtual void G() {}
      virtual ~AStructWithTwoVirtualFunction() {}
    };
    cout << "AStructWithOneFunction size is:" << sizeof(AStructWithOneFunction)
         << endl;  // AStructWithOneFunction size is:1
    cout << "AStructWithOneVirtualFunction size is:"
         << sizeof(AStructWithOneVirtualFunction)
         << endl;  // AStructWithOneVirtualFunction size is:1
    cout << "AStructWithTwoVirtualFunction size is:"
         << sizeof(AStructWithTwoVirtualFunction)
         << endl;  // AStructWithTwoVirtualFunction size is:1
  }
  {
#define P(EX) cout << #EX << ":" << EX << endl;
    int a = 4;
    P(a + 43);  // a+43:47
//		cout<<#(a+2)<< " "<<a+2<<endl;	// 错误：程序中有游离的‘#’

#define ADC_SPI 5
#define COMB_SPI_INFO(name) TEMP(name)
#define TEMP(name) "SPI/" #name

    cout << COMB_SPI_INFO(ADC_SPI) << endl;

    void (*func_table[])() = {b, c, d};
    for (int i = 0; i < 3; ++i) {
      (*func_table[i])();
    }

#define FIELD(a)    \
  char *a##_string; \
  int a##_size;
    FIELD(x);
    FIELD(y);
    FIELD(z);
    x_string = NULL;
    x_size = 10;
    //		return 0;
  }
  /*	{
   union X{
   int i;
   float f;
   char c;
   };
   X x;
   x.f = 2.2;
   cout<<x.i<<endl;	// 1074580685
   }*/
  //	reinterpret_cast
  //	static_cast;
  //	dynamic_cast
  //	const_cast
  {
    //		mallopt(M_CHECK_ACTION, 0);
    malloc_trim(0);
    malloc_stats();
    cerr << "1--------" << endl;

    char *p[15];
    //		for (int i = 0; i < 10; ++i)
    //			p[i] = (char*)malloc(500);

    p[10] = (char *)malloc(5000);
    p[11] = (char *)malloc(4000);
    p[12] = (char *)malloc(5000);
    p[13] = (char *)malloc(4000);
    p[14] = (char *)malloc(5000);

    malloc_stats();
    cerr << "2--------" << endl;
    free(p[14]);
    free(p[11]);
    free(p[13]);

    struct mallinfo info = mallinfo();
    cout << info.keepcost << endl;

    malloc_stats();
    cerr << "3--------" << endl;
    malloc_trim(0);
    malloc_stats();
    cerr << "4--------" << endl;
    free(p[10]);
    free(p[12]);

    p[0] = (char *)malloc(1024);
    malloc_stats();
    cerr << "5--------" << endl;
    free(p[0]);
    p[0] = NULL;
    malloc_stats();
    cerr << "6--------" << endl;
    //		for (int i = 0; i < 10; ++i)
    //			free(p[i]);

    cout << "freed successfully" << endl;
    //		return 0;
  }

  /*	{
   char *p;
   if (mallopt(M_CHECK_ACTION, 3) != 1) {	//
   打印详细的错误信息，然后继续执行。不在eclipse环境中运行，可以打印信息，否则打印不了，很奇怪
   fprintf(stderr, "mallopt() failed\n");
   exit(EXIT_FAILURE);
   }

   p = (char*)malloc(1000);
   if (p == NULL) {
   fprintf(stderr, "mallac() failed\n");
   exit(EXIT_FAILURE);
   }

   free(p);
   printf("first free() returned\n");
   free(p);
   printf("second free() returned\n");
   exit(EXIT_SUCCESS);
   }
   */

  /*
   {
   // 申请的空间大小s和实际占用的空间大小t的关系为：  t = max(32, (s+8)align16);
   即使s=0，t=32.
   //
   M_MXFAST表示使用fastbins内存申请的最大值，即大于该阈值的内存不使用fastbins，其缺省值为64。
   //		mallopt(M_MXFAST, 0);	//	设置其为0，表示禁用fastbins
   char *p1 = (char*)calloc(0, 1);
   p1[1] = 'a';
   char *p2 = (char*)calloc(10, 1);
   char *p3 = (char*)malloc(20);
   char *p4 = (char*)malloc(1);	// 仍然占用了0x20的空间
   char *p5 = (char*)malloc(7);
   printf("%p %p %p %p %p\n", p1, p2, p3, p4, p5);	//	0x1c80060
   0x1c80080 0x1c800a0 0x1c800c0 0x1c800e0
   //		for (int i = 0; i < 4; ++i){
   //			bitset<8> a((int)p1[i]);
   //			cout<<a<<"-";
   //		}
   //		cout<<endl;
   //		for (int i = 0; i < 4; ++i){
   //			bitset<8> a((int)p2[i]);
   //			cout<<a<<"-";
   //		}
   //		cout<<endl;

   free(p1);free(p2);

   //		for (int i = 0; i < 4; ++i){
   //			bitset<8> a((int)p1[i]);
   //			cout<<a<<"-";
   //		}
   //		cout<<endl;
   //		for (int i = 0; i < 4; ++i){
   //			bitset<8> a((int)p2[i]);
   //			cout<<a<<"-";
   //		}
   //		cout<<endl;

   struct mallinfo info = mallinfo();	// 获得有关malloc内存信息的结构体
   cout<<"fastbin held "<<info.fsmblks<<endl;
   char *p = (char*)malloc(30);
   printf("%p\n",p);	//	M_MXFAST设置为0：	0x1c80060
   //	M_MXFAST未设置：		0x1c80100

   free(p3);free(p4);free(p5);
   return 0;
   }
   */

  {  // 使用swap来释放vector占用的额外内存
    int x = 10;
    vector<int> myvector(10000, x);

    //这里打印仅仅是元素的个数不是内存大小
    cout << "myvector size:" << myvector.size() << endl;

    cerr << " ---------------- " << endl;
    cerr << " ---------------- " << endl;
    malloc_stats();
    for (unsigned k = 0; k < 10000 - 1; ++k) myvector.pop_back();
    // swap交换函数释放内存：vector<T>().swap(X); 仅仅是释放内存，但不归还给系统
    // T:int ; myvertor代表X
    //		    vector<int>(myvector).swap(myvector);	// don't return
    // memory
    // to
    // os
    //    myvector.shrink_to_fit();  // C++11, return memory to os
    //    // nothing changed??

    //两个输出仅用来表示swap前后的变化
    cout << "after swap :" << myvector.size() << endl;

    cerr << " ---------------- " << endl;
    malloc_stats();
    //		    return 0;
  }

  /*	{
   // get number of processors
   int procs = (int)sysconf(_SC_NPROCESSORS_ONLN);
   cout<<procs<<endl;
   }*/
  {  // something in misery about rvalue

    int a = 0;
    //		long &ref = a;	// error
    //		const int* ref = &a;
    //		const int* &b = ref;

    //		const int* &b = &a;

    //		b = &a;

    cout << sizeof(&a) << " " << sizeof(a) << endl;  // 8 4
                                                     //		return 0;
  }
  /*
   {	// direct lock 和 guardlock 性能相近无几
   int i = 0;
   int count = 10000000;
   pthread_mutex_init(&mutex, NULL);

   struct timeval start, end;
   gettimeofday(&start, NULL);
   cout<<"start"<<endl;
   for (i = 0; i < count; ++i) {
   DirectLock();
   //			cout<<i;
   }
   cout<<endl;
   gettimeofday(&end, NULL);
   cout<<"direct lock:"<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec
   - start.tv_sec) * 1000<<"ms"<<endl;	//	direct lock:201.334ms

   gettimeofday(&start, NULL);
   for (i = 0; i < count; ++i) {
   GuardLock();
   //			cout<<i;
   }
   cout<<endl;
   gettimeofday(&end, NULL);
   cout<<"guard lock:"<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec -
   start.tv_sec) * 1000<<"ms"<<endl;	//	guard lock:199.307ms

   pthread_mutex_destroy(&mutex);

   return 0;
   }*/

  {
    int a[12] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *a1 = a;
    cout << (void *)a << " " << a << ":" << (void *)(a + 1) << " " << a + 1
         << endl;  //	0x7fff1d46eb00 0x7fff1d46eb00:0x7fff1d46eb04
    // 0x7fff1d46eb04---- because of int type

    cout << sizeof(int) << endl;  // 4
    cout << (void *)ptr << " " << (void *)ptr_next_size() << " "
         << (void *)ptr_next_ptr()
         << endl;  //	0x17ac040 0x17ac043 0x17ac027	---- char* type
                   //    return 0;
  }

  /*
   {//mutex lock&unlock need average 16ns, overhead can be three smaller by
   using atomic function like __sync_add_and_fetch
   pthread_mutex_t lock;
   pthread_mutex_init(&lock, NULL);
   struct timeval start, end;
   {
   gettimeofday(&start, NULL);

   int k = 0;
   for (int i = 0; i < 1000000; ++i) {
   k = k + 2;
   }
   gettimeofday(&end, NULL);
   cout<<"no lock:"<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec -
   start.tv_sec) * 1000<<"ms"<<endl;	//	no lock:2.437ms
   }
   {
   gettimeofday(&start, NULL);

   int k = 0;
   for (int i = 0; i < 1000000; ++i) {
   pthread_mutex_lock(&lock);
   k = k + 2;
   pthread_mutex_unlock(&lock);
   }
   gettimeofday(&end, NULL);
   cout<<"mutex lock:"<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec -
   start.tv_sec) * 1000<<"ms"<<endl;	//	mutex lock:18.885ms
   }
   {
   gettimeofday(&start, NULL);

   int k = 0;
   for (int i = 0; i < 1000000; ++i) {
   __sync_add_and_fetch(&k, 2);
   }
   gettimeofday(&end, NULL);
   cout<<"atomic operation lock:"<<(double)(end.tv_usec -
   start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<"ms"<<endl;	//
   atomic operation lock:6.576ms
   }
   //		return 0;
   }
   */

  /*
   {
   int *p1, *p2, *p3;
   struct timeval start, end;
   int* p[1001];
   int i = 0, j = 0;

   {
   gettimeofday(&start, NULL);
   p1 = (int*)malloc(40000*sizeof(int));
   memset(p1, 0, 40000*sizeof(int));
   gettimeofday(&end, NULL);
   cout<<"1--"<<(void*)p1<<"--"<<(double)(end.tv_usec -
   start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<"ms"<<endl;

   }
   for (i = 0; i < 1000; ++i) {
   p[i] = (int*)malloc(1000*sizeof(int));
   }

   cout<<"p[0]:"<<(void*)p[0]<<"-- p[999]:"<<(void*)p[999]<<endl;
   malloc_stats();
   cerr<<"start free all memory but the last -------------"<<endl;

   for (i = 998; i >= 0; --i) {
   free(p[i]);
   p[i] = NULL;
   }
   malloc_stats();	//		Arena 0:
   //		system bytes     =    4190208
   //		in use bytes     =     124112
   //		Total (incl. mmap):
   //		system bytes     =    4190208
   //		in use bytes     =     124112
   //		max mmap regions =          0
   //		max mmap bytes   =          0

   cerr<<" start free the last memory-------------"<<endl;
   free(p[999]);
   p[999] = NULL;

   // 未释放堆上的最顶部内存块，所有内存是不会还给系统的。
   malloc_stats();	//		Arena 0:
   //		system bytes     =     253952
   //		in use bytes     =     120096
   //		Total (incl. mmap):
   //		system bytes     =     253952
   //		in use bytes     =     120096
   //		max mmap regions =          0
   //		max mmap bytes   =          0

   cerr<<"malloc two large memory-------------"<<endl;


   //  malloc一个大块内存，结果是映射区的内存地址
   {
   gettimeofday(&start, NULL);
   p2 = (int*)malloc(0x30000/4*sizeof(int));
   memset(p2, 0, 0x30000/4*sizeof(int));
   gettimeofday(&end, NULL);
   cout<<"2--"<<(void*)p2<<"--"<<(double)(end.tv_usec -
   start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<"ms"<<endl;
   }

   {
   gettimeofday(&start, NULL);
   p3 = (int*)malloc(0x30000/4*sizeof(int));
   memset(p3, 0, 0x30000/4*sizeof(int));
   gettimeofday(&end, NULL);
   cout<<"3--"<<(void*)p3<<"--"<<(double)(end.tv_usec -
   start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<"ms"<<endl;
   }

   malloc_stats();	//		Arena 0:
   //		system bytes     =     253952
   //		in use bytes     =     120096
   //		Total (incl. mmap):
   //		system bytes     =     655360
   //		in use bytes     =     521504
   //		max mmap regions =          2
   //		max mmap bytes   =     401408

   cerr<<"-------------"<<endl;
   //		malloc_info();
   //		malloc_trim();
   free(p1);free(p2);free(p3);
   return 0;

   }
   */

  /*	{	// 测试 hash函数
   //		static int num = 0;
   TestHashFunc(&Hash1);
   TestHashFunc(&Hash2);
   TestHashFunc(&Hash3);
   TestHashFunc(&Hash4);
   TestHashFunc(&Hash5);
   TestHashFunc(&Hash6);
   return 0;
   }*/
  /*
   {
   int a = 0xF0000000;
   a = a >> 2;	// 仅当有符号数首位为1时 右移高位填1
   bitset<32> bs(a);
   cout<<bs<<endl;	// 转二进制
   return 0;

   }
   */

  /*

   {
   cout<<RAND_MAX<<endl;	//	2147483647 = INT_MAX
   int a;
   cout<<"sizeof int:"<<sizeof(a)<<" sizeof long:"<<sizeof(long)<<endl;	//
   sizeof int:4 sizeof long:8
   cout<<"sizeof float:"<<sizeof(float)<<" sizeof
   double:"<<sizeof(double)<<endl;	// sizeof float:4 sizeof double:8

   cout<<"INT_MAX:"<<INT_MAX<<endl;	//	INT_MAX:2147483647
   return 0;
   }
   */

  /*
   {
   // malloc
   底层也是内存池相似的机制，os维护一个空闲的内存块队列，从中找到够大的内存块，截断size大小的块返回，剩余的块加入到队列尾
   //		malloc_stats();

   struct timeval start, end;
   char *m;
   gettimeofday(&start, NULL);
   for (int i = 0; i < 100000; ++i) {
   m = (char*)malloc(1000 * sizeof(char));
   free(m);
   }
   gettimeofday(&end, NULL);
   cout<<"malloc&free use "<<(double)(end.tv_usec -
   start.tv_usec)/1000+(end.tv_sec - start.tv_sec) * 1000<<" ms"<<endl;
   //malloc&free use 4.082 ms
   //		malloc_stats();

   gettimeofday(&start, NULL);
   for (int i = 0; i < 100000; ++i)
   m = (char*)malloc(1000 * sizeof(char));

   gettimeofday(&end, NULL);
   cout<<"malloc use "<<(double)(end.tv_usec - start.tv_usec)/1000+(end.tv_sec -
   start.tv_sec) * 1000<<" ms"<<endl;	//		malloc use 29.812 ms
   //		malloc_stats();
   return 0;
   }
   */

  /*
   {
   list<int> l{1,2,3};
   auto pos = l.begin();
   pos++;
   l.insert(pos, 4);	// insert a item, then the pos move back one step
   cout<<*pos<<endl;	//	2
   for (auto it = l.begin(); it != l.end(); ++it) {
   cout<<*it<<" ";		//	1 4 2 3
   }
   return 0;
   }
   */

  /*
   {
   char a[] = "/home/imdb/桌面/Archive/public";
   char *p = realpath(a, NULL);
   cout<<sizeof(a)<<" "<<sizeof(p)<<endl;	// 33 8, because p is a
   pointer,whose size always is 8
   cout<<getpagesize()<<endl;	// 4096
   cout<<sizeof(bool)<<"-"<<sizeof(char)<<endl;	// 1-1
   //		return 0;
   }
   */

  /*
   {
   timeval start, end;
   char *test1=NULL, *test2 = NULL,*test3 = NULL,*test4 = NULL,*test5 = NULL;
   gettimeofday(&start, NULL);
   test1 = (char*)malloc(2*1024*1024*sizeof(char));
   gettimeofday(&end, NULL);
   cout<<end.tv_sec-start.tv_sec<<"second "<<end.tv_usec-start.tv_usec<<"
   microsecond"<<endl;	//	without memset: 0 second 3 or 4 microsecond

   gettimeofday(&start, NULL);
   test2 = (char*)malloc(2*1024*1024*sizeof(char));
   memset(test2, 0, sizeof(test2));
   gettimeofday(&end, NULL);
   cout<<end.tv_sec-start.tv_sec<<"second "<<end.tv_usec-start.tv_usec<<"
   microsecond"<<endl;	//	with memset: 0 second 4 or 5 microsecond

   gettimeofday(&start, NULL);
   test3 = (char*)malloc(2*1024*1024*sizeof(char));
   memset(test3, 0, sizeof(test3));
   test3[0] = 'a';
   test3[1] = 'b';
   gettimeofday(&end, NULL);
   cout<<end.tv_sec-start.tv_sec<<"second "<<end.tv_usec-start.tv_usec<<"
   microsecond"<<endl;	//	with memset and two assign: 0 second 4 or 5
   microsecond
   cout<<test3[0]<<" "<<test3[1]<<endl;

   free(test4);	free(test1);free(test2);	free(test3); free(test5);
   //		return 0;
   }
   */

  /*
   {
   vector<int> v{12,23};
   for (auto i:v) {	// i is item rather than iterator
   cout<<i<<endl;
   }
   //		return 0;
   }
   */

  /*	{
   unsigned int a = -1;
   cout<<a++<<endl;	// 4294967295
   cout<<a++<<endl;	// 0
   cout<<a++<<endl;	// 1
   return 0;
   }
   */
  /*
   {
   if(close(-1) != -1) {
   OutputFormatInfo("close ok");
   }
   else {
   perror("");	// Bad file descriptor
   }
   close(-1);
   cout<<"return"<<endl;
   //				return 0;
   }
   */

  /*	{
   char buf[] = "hello\n";
   cout<<sizeof(buf)<<endl;
   if (write(1, buf, sizeof(buf)) < 0) {	// 1-stdout
   perror("send to 1 failed");
   }
   if (write(2, buf, sizeof(buf)) < 0) {	// 2-stderr
   perror("send to 2 failed");
   }
   cout<<"========="<<endl;	//	无法输出
   cerr<<"========="<<endl;	//	无法输出
   //		cout<<endl<<"========="<<endl;	// 加上endl即可输出
   //		cerr<<endl<<"========="<<endl;
   return 0;
   }
   */
  /*
   {
   // (pointer - pointer) is not (addr1 - addr2), but (addr1 - addr2)/(pointer
   size)
   long a = 1;
   long b = 2;
   long *p1 = &a;
   long *p2 = &b;
   cout<<(void*)p1<<" "<<(void*)p2<<" "<<p1-p2<<endl;	//	0x7fff90a9c820
   0x7fff90a9c818 1
   //		return 0;
   }
   */

  /*
   {// 转化十进制到二进制
   int ii = 33;
   bitset<32> bs(ii);
   cout<<bs<<endl;	//	00000000000000000000000000100001
   return 0;
   }
   */

  {
    {  // 小端字节序，比如a = 0x00000004， 在内存中就是存为
       // 0x04,0x00，0x00，0x00
      int a = 4;
      int *p = &a;
      char *cp = (char *)p;
      cout << (int)((char *)p)[0] << (int)cp[1] << (int)cp[2] << (int)cp[3]
           << endl;
      char *buffer = (char *)malloc(8);
      *(int *)buffer = a;
      cout << (int)buffer[0] << "--" << (int)buffer[1] << "--" << (int)buffer[2]
           << "--" << (int)buffer[3] << endl;  // 4--0--0--0
    }

    int kk = 0x01030012;
    int *pp = &kk;
    cout << int(*(((char *)pp) + 0)) << "--" << int(*(((char *)pp) + 1)) << "--"
         << int(*(((char *)pp) + 2)) << "--" << int(*(((char *)pp) + 3))
         << endl;        // 18--0--3--1
    cout << kk << endl;  // 16973842
    cout << "----" << endl;

    long i[2];
    i[0] = 0x0000000200000001;
    i[1] = 0x0000000200001001;
    long **p = (long **)&i;

    //		cout<<(((int*)p)+k)<<endl;
    cout << int(*(((int *)p) + 0)) << "--" << int(*(((int *)p) + 1)) << "--"
         << int(*(((int *)p) + 2)) << "--" << int(*(((int *)p) + 3))
         << endl;  // 1--2--4097--2
  }
  {
    cout << "kong:		" << sizeof(kong) << endl;
    cout << "bird:		" << sizeof(bird) << endl;
    cout << "kongbird:	" << sizeof(kongbird) << endl;
    //		kongbird kb;
    bird *p = new kongbird();
    p->PrintNum();  //子类和基类的虚函数必须一致，包括是否为const，否则仍调用bird的方法，因为子类的虚函数会覆盖另一基类的虚函数
    // kb.PrintNum();		// 歧义，两个基类都有该虚函数
    //				return 0;
  }

  {
    char *a = "abcdefg'\''";
    a += 2;
    string aa;
    aa = string(a, 8);
    //		aa += "'\''";
    cout << aa.length() << "--" << aa << endl;  // “s”
    cout << sizeof(a) << "--" << a[3] << endl;
    //		return 0;

    //		for (long i = (long)a-200; i < (long)a+3; i++) {
    //						char *t = (char*)i;
    //						printf("%ld:%p:%c\n", i, t, *t);
    //					}
  }
  /*	{
   vector<CC*> ccc;
   aaa(ccc);
   cout<<&(ccc.at(0))<<endl;	//
   在函数中push指针的类对象仍存在vector中，在push时候重新在堆中复制构造了指向的类对象
   cout<<&(ccc.at(1))<<endl;	// 地址位于堆中
   }*/

  {                                              // malloc
                                                 // 分配哪里的内存,很大和很小的分别为两个地方的内存，默认小余128kB内存使用brk（）在堆中分配，大内存使用mmap（）在映射区分配内存
    int *p1 = (int *)malloc(100 * sizeof(int));  // 堆
    int *p2 = (int *)malloc(1000000 *
                            sizeof(int));  // 映射区	---->准确说是虚拟内存
    printf("p1:			%p\n", p1);
    printf("p2:			%p\n", p2);
    free(p1);
    free(p2);

    // new is same as malloc
    int *new1 = new int[5];
    int *new2 = new int[10000000];
    printf("new1:			%p\n", new1);
    printf("new2:			%p\n", new2);
    delete (new1);
    delete new2;
  }

  /*  {
     cpu_set_t cpu_set;
     CPU_ZERO(&cpu_set);		// 在标准库中
   }
   {
     cout << "kong: " << sizeof(kong) << endl;
   }

   /*
    {
    int b = 123;
    int &a = b;
    cout<<&b<<"==="<<&a<<endl; // equal!!!
    }
    */
  /*{
   //concurrent write file
   pthread_t thread1, thread2;
   char a = 'a';
   char b = 'b';
   pthread_create(&thread1, NULL, &WriteFile, &a);
   pthread_create(&thread2, NULL, &WriteFile, &b);

   result likes this:
   *  bbbbbbbbbbbbaaaaaaaaaaaaaaabbbbaaaa

   }*/

  {
    bird a;
    FlyBird b(10);
    b.print();
  }

  Node a(1);
  {
    Node a(152);
    Node b(14);
    multiset<int, bool (*)(const Node &a, const Node &b)> ms(
        IsSmaller);  //自定义结构
    ms.insert(a.type);
    ms.insert(b.type);

    ostream_iterator<int> ostr_iter(cout, " ");
    copy(ms.begin(), ms.end(), ostr_iter);
    cout << endl;
  }
  /*	{	// delete self,删除自己
   malloc_stats();
   for (int i = 0; i < 100000; ++i) {
   NoDefault *a = new NoDefault(2);
   //			a->print_mem();
   //			cout<<"try to delete self"<<endl;
   a->DeleteSelf();	// really did work, according to memory usage
   //			if (a) {	// a is not null even if a is deleted,
   so
   true
   //				a->print_mem();
   //			}
   }
   cerr<<"-----------------"<<endl<<"------------------"<<endl;
   malloc_stats();
   //		delete a;

   //		NoDefault b(11);
   //		b.DeleteSelf();
   //		b.print_mem();
   }*/
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
    fill(v.begin(), v.end(), 23);
    for (int i = 0; i < 10; ++i) v.push_back(i);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
      cout << *it << "-";
    //		for_each(v.begin(), v.end(), [](const int t){return t;});
    cout << endl;

    // Usage of ostream_iterator
    ostream_iterator<int> out_iter(cout, " ");
    // one
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
      *out_iter++ = *it;  // *out_iter, out_iter++ all return out_iter
    cout << endl;
    // two
    copy(v.begin(), v.end(), out_iter);
    cout << endl;

    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), out_iter);
    cout << endl;

    sort(v.rbegin(), v.rend());
    copy(v.begin(), v.end(), out_iter);
    cout << endl;
  }

  { //数组不支持begin和end
    //		int a[] = {1,1,1,1,23};
    //		int *res = find(begin(a), end(a), 23);
    //		cout<<res==end(a)?"No find":"Find"<<endl;
  }
  {
    ostringstream ostr;
    ostr << "hello";
    insert(ostr, 123);
    cout << ostr.str() << endl;
    //				ostr..clear();	//ss.clear();
    ////实际上，它并不清空任何内容，它只是重置了流的状态标志而已！
    //				cout<<ostr.str()<<endl;
    ostr.str("");  // ss.clear(); //清空
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
  /*{
   cout<<"---------------"<<endl;
   {
   TestForReturnConst t;
   vector<int> v = t.getV();
   cout<<v.empty()<<endl;	// put: 1
   v.push_back(12);
   cout<<v.at(0)<<endl;		// put: 12
   }
   cout<<"============================="<<endl;
   }*/
  {
    //		int i = 23;
    //		void *v = &i;
    //		char *c = "fs";
    //		void *v1 =c;
    //		char c1= 'v';
    //		void *v2 = &c1;
    //		printf("%d,%d,%d\n",get_int_from_void(v), get_int_from_void(c),
    // get_int_from_void(v2));//put: 23,620786534,6006
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
    //		NoDefault *p_n1 = NoDefault(12);
    ////错误：不能将‘NoDefault’转换为‘NoDefault*’，在 initialization 中
    NoDefault *p_n2 = new NoDefault(12);
    p_n2->print_mem();
  }

  {
    // default constructor test
    C c;
    c.print_mem();

    //		vector<NoDefault> vec(10);	//
    //错误：对‘NoDefault::NoDefault()’的调用没有匹配的函数
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
  /*	{
   int _t, __t, ___t, _SS;	// __t is not certain
   cout<<_t<<" "<<__t<<" "<<___t<<" "<<_g<<" "<<_SS<<endl;	//	32767 ?
   -2147090392 0 1111804544
   }*/

  /*	{
   int tt;
   string sst;
   cout<<tt<<"-"<<sst<<"="<<endl;	// put: 32767-=
   }*/
  {
    //		int testforc11{235.56};
    //		cout<<testforc11<<endl;	// put: 235
  }
  /*	{
   char ch = 21333;
   char ch1 = ch %256;
   cout<<(ch==ch1)<<"---";	// ch = ch1
   cout<<ch<<endl;	// put: U
   }*/
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
  //	   for(i=0; i<2; i++){getIteratorTree
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
    //		printf("sizeof(i++) is: %d\n",sizeof(ii++));	//
    //编译器编译阶段
    //直接得到值为4，不执行ii++
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
    cout << ll << endl;  // 18446 74407 37095 51615
    cout << numeric_limits<long double>::max() << " " << LONG_MAX
         << endl;  // 1.18973e+4932 9223372036854775807
    cout << "int max is: " << numeric_limits<int>::max()
         << endl;  // int max is: 2147483647
    cout << numeric_limits<long double>::max_exponent10 << endl;
    cout << sizeof(int) << " " << sizeof(long) << endl;
    cout << sizeof(float) << endl;
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
  Node *p1 = (Node *)malloc(sizeof(Node));
  p1->p = &i;
  p1->type = 4;

  newNode(0);
  newNode(1);
  newNode(2);
  newNode(3);
  cout << pp[0] << "-" << pp[1] << "-" << pp[2] << "-" << pp[3] << endl;

  cout << p1->p << endl;
  Node **p2;
  p2 = &p1;
  free(*p2);
  *p2 = NULL;
  p2 = NULL;
  free(p1);
  cout << p2 << endl;  // put: 0
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

  /*{
   int temp;
   string t;
   while (cin>>temp);	// if input 's', return false and the 's' will be
   saved in buffer.
   cin.clear();
   if(cin>>t) cout << "Success !";
   else cout << "Error!";
   cout<<t<<endl;	// 's'
   }*/
  cout << "---------------" << endl;
  /*{
   int i;
   iostream::iostate old_state = cin.rdstate();

   // if cin.eof() return true or cin.bad() return true, then cin.fail() also
   return true
   while(cin>>i) cout<<cin.eof()<<"-"<< cin.fail()<<"-"<< cin.bad()<<endl;
   cout<<cin.eof()<<"-"<< cin.fail()<<"-"<< cin.bad()<<endl;
   cin.clear();
   cout<<cin.eof()<<"-"<< cin.fail()<<"-"<< cin.bad()<<endl;

   string s;
   cin>>s;
   }*/
  cout << "---------------" << endl;
  /*{
   int no_meaning;
   ostream *old_tie = cin.tie();
   cin.tie(&cerr);
   //将cin关联cerr，不再关联cout，按理说，读取cin不会刷新cout，貌似 验证失败
   cout<<"sndfisfn";cout<<"sndfisfn";cout<<"sndfisfn";cout<<"sndfisfn";cout<<"sndfisfn";cout<<"sndfisfn";
   cin>>no_meaning;
   cin.tie(old_tie);

   cout<<"sndfisfn";
   cin>>no_meaning;
   }*/
  cout << "---------------" << endl;
  {
    //		vector<int> v;	//default: capacity = 2^n;
    vector<int> v(5);  // capacity = 2^n * 5;
    cout << "size: " << v.size() << "  ";
    cout << "capacity: " << v.capacity() << endl;
    while (v.size() < 12) v.push_back(11);

    cout << "size: " << v.size() << "  ";
    cout << "capacity: " << v.capacity() << endl;

    v.reserve(44);
    while (v.size() < 32) v.push_back(111);

    cout << "size: " << v.size() << "  ";
    cout << "capacity: " << v.capacity() << endl;
  }
  cout << sizeof(void *) << endl;
  return 0;
}
