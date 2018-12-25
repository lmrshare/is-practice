#include "list1.h"
#include "memory.h"
#include "stdio.h"
//#include "string.h"


namespace l1
{
    void foo()
    {
        #undef a
        #define a 50
        printf("in file list1: %d\n",a);
    };
    int* p()
    {
        int p = 250;//p在栈上
        int *i = &p;
        return i;
    };
    void call_pp(pp func)
    {
        func(2, 3);
    }
    void mem()
    {
        char aa[100];
        char bb[50];
        memset(aa, ' ', sizeof(aa));
        memset(bb, '\0', sizeof(bb));
        memcpy(bb, aa, sizeof(bb));
        char aaa[100];
        char bbb[50];
//        cout << sizeof(aaa) << endl;
        memset(aaa, ' ', sizeof(aaa));
        memset(bbb, 'a', sizeof(bbb));
        mystrcpy(aaa, bbb);
//        cout << sizeof(aaa) << endl;
        char aaaa[100];
        char bbbb[100];
        memset(aaaa, 'a', sizeof(aaaa));
        memset(bbbb, 'b', sizeof(bbbb));
        mymemcpy(bbbb, aaaa, 2);
        mymemcpy(bbbb, aaaa, 3);
        mymemcpy(bbbb, aaaa, 4);
    }
    void mymemcpy(void *dest, void *src, unsigned int count)
    {
        assert(nullptr != dest && nullptr != src);
        assert((unsigned char*)dest > (unsigned char*)src + count || (unsigned char*)src > (unsigned char*)dest + count);//防止内存重叠
        unsigned char *bdest = (unsigned char*)dest;
        unsigned char *bsrc = (unsigned char*)src;
        while(count-->0)
            *bdest++ = *bsrc++;
    }
    void mystrcpy(char *dest, char *src)
    {
        assert(nullptr != dest && nullptr != src);
        char *address = dest;
        while((*dest++ = *src++) != '\0')
            continue;
    }
    void exe_sequence()
    {
        /*
         *a++和++a都是先自增，区别在于a++自增后将自增前的值通过临时变量返回
         * */
        int arr[] = {6, 7, 8, 9, 10};
        int *mp = arr;
        cout << *mp << " " << *mp++ << " " << *mp << endl;
        cout << *mp << " " << *++mp << " " << *mp << endl;
    }
    ClxBase::ClxBase(){};
    ClxBase::~ClxBase()
    {
        cout << "Output from the destructor of class ClxBase!" << endl;
    }
    void ClxBase::DoSomething() 
    {
        cout << "Do something in class ClxBase!" << endl; 
    };

    ClxDerived::ClxDerived(){};
    ClxDerived::~ClxDerived()
    {
        cout << "Output from the destructor of class ClxDerived!" << endl;
    }
    void ClxDerived::DoSomething()
    {
        cout << "Do something in class ClxDerived!" << endl;
    }
    ClxBase1::ClxBase1(){};
    ClxBase1::~ClxBase1()
    {
        cout << "Output from the destructor of class ClxBase1!" << endl;
    }
    void ClxBase1::DoSomething()
    {
        cout << "Do something in class ClxBase1!" << endl;
    }
    ClxDerived1::ClxDerived1(){};
    ClxDerived1::~ClxDerived1()
    {
        cout << "Output from the destructor of class ClxDerived1!" << endl;
    };
    void ClxDerived1::DoSomething()
    {
        cout << "Do something in class ClxDerived1!" << endl;
    }
    void write_file()
    {
        FILE *fp;
        char ch, filename[50];
        scanf("%s", filename);//屏幕向变量
        if((fp = fopen(filename, "w")) == nullptr)
        {
            printf("can not open file\n");
            exit(0);
        }
        ch = getchar();//delete the first '\n'
        while((ch = getchar()) != '#')//从屏幕读入字符
        {
            fputc(ch, fp);//向文件写入字符
            putchar(ch);//向屏幕输出字符
        }
        fclose(fp);
    }
    void read_file()
    {
        FILE *fp;
        char ch, filename[50];
        scanf("%s", filename);
        if((fp = fopen(filename, "r")) == nullptr)
        {
            printf("can not open file: %s\n", filename);
        }
        while((ch = fgetc(fp)) != EOF)
        {
            putchar(ch);
        }
        fclose(fp);
    }
    int human::human_num = 0;//类中静态数据成员在外部定义，仅定义一次
    human::human()
    {
        human_num++;
    }
    human::~human()
    {
        human_num--;
        print();
    }
    void human::print()
    {
        cout << "human num is: " << human_num << endl;
    }
    human f1(human x)
    {
        x.print();
        return x;//f1调用结束后会释放栈对象x, 因此要调用human的析构函数
    }
}
