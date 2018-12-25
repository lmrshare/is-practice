/*
 *有能力、不放弃, 那希望一定常在.
 *放弃的话就等于比赛提前结束了.
 * */
#include "list1.h"

void pp_impl(int aa, int bb);
void test_virtual_sequence();
void test_virtual_resource1();
void test_virtual_resource2();
void test_foo();
void test_pointer();
void test_memmory();
void test_exesequence();
void test_write_file();
void test_classknowledge();
#if 0//打开这段代码会发现test_foo的执行结果变了
void foo1()
{
#undef a
#define a 50
};
#endif
int main()
{
    test_classknowledge();
  //test_pointer();
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
void test_foo()
{
    printf("%d..",a);
    l1::foo();
    printf("%d",a);
}
void test_pointer()
{
    //TOPIC: pointer[基础类型的栈、堆问题]
    /*
     *得看具体哪个时候系统复用了那块内存，只要复用了，值为任何值都有可能
     * */
    using namespace l1;
    int *aa = p();
    printf("1. Output2: %d\n", *aa);
    cout << "1. Output1: " << *aa << endl;
    printf("1. Output2: %d\n", *aa);
    
    int ppp = 250;
    int *aaa = &ppp;
    printf("2. Output2: %d\n", *aaa);
    cout << "2. Output1: " << *aaa << endl;
    printf("2. Output2: %d\n", *aaa);

    //函数指针模拟callback
    pp func = &pp_impl;
    call_pp(func);
}
void pp_impl(int aa, int bb)
{
    cout << "\n---\nmain_impl: " << aa << " , " << bb << endl;
}
void test_memmory()
{
    using namespace l1;
    mem();
}
void test_exesequence()
{
    using namespace l1;
    exe_sequence();
}
void test_write_file()
{
    l1::write_file();
    cout << "read the file" << endl;
    l1::read_file();
}
void test_classknowledge()
{
    using namespace l1;
    human h1;//调用默认构造函数, human_num变为1
    h1.print();//打印human_man:1
    human h2 = f1(h1);//先调用函数f1, 输出human_num:1, 而后输出human_num为0
    h2.print();//打印输出human_num:0
    /*
     *1. 依次调用两个析构函数
     * */
}
