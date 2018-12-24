#ifndef CHn
#define CHn
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace l1
{
  class sectionn_n_n
  {
    public:
      //n.n.n demo function
      int demofunction(vector<int>& nums);
  };
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
}
#endif
