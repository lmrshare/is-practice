#include "list1.h"

void test_virtual_sequence();
void test_virtual_resource1();
void test_virtual_resource2();

int main()
{
  test_virtual_resource2();
  return 0;
}
void test_virtual_sequence()
{
    /*
     *析构顺序: 先派生类、再子类.
     * */
    using namespace l1;
    ClxDerived *p =  new ClxDerived;
    p->DoSomething();
    delete p;
}


void test_virtual_resource1()
{
    /*
     *只析构了基类资源(因为基类的析构函数不是虚函数), 内存泄漏!
     * */
    l1::ClxBase *p =  new l1::ClxDerived;
    p->DoSomething();
    delete p;
}

void test_virtual_resource2()
{
    /*
     *相比于test_virtual_resource1, 本例正确释放资源(析构函数是虚函数), 不会造成内存泄漏!
     * */
    using namespace l1;
    ClxBase1 *p = new ClxDerived1;
    p->DoSomething();
    delete p;
}
