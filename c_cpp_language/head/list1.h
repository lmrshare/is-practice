#ifndef LIST1
#define LIST1
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;
#define a 10

namespace l1
{
  void foo();
  int* p();
  typedef void (*pp)(int, int);
  void call_pp(pp func);
  void mem();
  void mystrcpy(char *dest, char *src);
  void mymemcpy(void *dest, void *src, unsigned int count);
  void exe_sequence();
  //TOPIC1: 构造函数为什么不能为虚函数?
  /*解释一: 存储空间的角度
   *1. 虚函数相对应一个指针(指向vtable虚函数表), 这个指针存储在对象的内存空间中.
   *2. 虚函数是通过对象内的指针指向的vtable来进行调用的.
   *3. 如果构造函数为虚函数, 显然没办法根据2实现(对象没有实例化, 内存空间还没有, 自然指向vtable的指针就不存在, 鸡生蛋蛋生鸡了吧, 混蛋).
   * */
  //TOPIC2: 为什么基类的析构函数是虚函数?
  /*解释: 多态
   *1. 基类操作派生类, 在析构时防止仅仅析构基类而不析构派生类的状况发生.
   * */
  class ClxBase
    {
        public:
            ClxBase();
            ~ClxBase();
            void DoSomething();
    };
  class ClxBase1
  {
      public:
          ClxBase1();
          virtual ~ClxBase1();
          virtual void DoSomething();
  };
  class ClxDerived : public ClxBase
    {
        public:
            ClxDerived();
            ~ClxDerived();
            void DoSomething();
    };
  class ClxDerived1 : public ClxBase1
    {
        public:
            ClxDerived1();
            ~ClxDerived1();
            void DoSomething();
    };
  /*
   *TOPIC3: 多态
   *1. 含有纯虚函数的类称为抽象类, 不能实例化对象, 主要用作接口类.
   * */
  /*TOPIC4; 变量
   *1. 全局变量的生命周期是整个程序运行的时间, 局部变量的声明周期则为: 局部函数或过程被调用的时间段
   *2. 分配时机: 全局变量在main函数调用后就开始分配, 局部变量在用户栈中动态分配, 静态变量在main函数前就已经初始化了.
   * */
  /*TOPIC4: 文件读写
   * */
  void write_file();
  void read_file();
  /*
   *TOPIC: 类
   * */
  class human
  {
      public:
          human();
          ~human();
          static int human_num;//静态成员
          void print();
      protected:
      private:
  };
  human f1(human x);
}
#endif
