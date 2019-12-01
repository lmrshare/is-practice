#include "ch3.h"
using namespace std;

//3.2
void test_strStr();

int main ()
{
  test_strStr();
  return 0;
}

void test_strStr()
{
    string haystack = "hello the next task";
    string needle = "next";
    int pos = p3::strStr(haystack, needle);
    std::cout << "The position of needle is: " << pos << std::endl;
}