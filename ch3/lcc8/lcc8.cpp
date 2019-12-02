#include "ch3.h"
using namespace std;

void test_myAtoi();

int main ()
{
  test_myAtoi();
  return 0;
}

void test_myAtoi()
{
    string str = "2147483646";
    int value = p3::myAtoi(str);
    std::cout << "The str is: " << str << std::endl;
    std::cout << "The val is: " << value << std::endl;
}