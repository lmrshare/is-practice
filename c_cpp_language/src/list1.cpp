#include "list1.h"

namespace l1
{
  int sectionn_n_n::demofunction(vector<int>& nums)
  {
    cout << "demo function" << endl;
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
}
