#include "chn.h"
//exp[this part can be removed]
#include <functional>
#include <iostream>
#include <string>

void test_sectionn_n_n();
void exp();

int main()
{
  exp();
  return 0;
}
void test_sectionn_n_n()
{
  pn::sectionn_n_n* C = new pn::sectionn_n_n();
  vector<int> ints;
  C->demofunction(ints);
}
void exp()
{
    char ntr1[] = "Test";
    char ntr2[] = "Test";
    std::string str1(ntr1);
    std::string str2(ntr2);
    std::hash<char*> ptr_hash;
    std::hash<std::string> str_hash;
    std::cout << std::boolalpha;
    std::cout << "ntr1 and ntr2: " << (ptr_hash(ntr1) == ptr_hash(ntr2)) << std::endl;
    std::cout << "str1 and str2: " << (str_hash(str1) == str_hash(str2)) << std::endl;
    std::cout << "hash value:" << ptr_hash(ntr1) << " , " << ptr_hash(ntr2) << " , " << str_hash(str1) << " , " << str_hash(str2) << std::endl;
}
