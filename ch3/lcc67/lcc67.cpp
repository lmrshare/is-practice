#include "ch3.h"
using namespace std;

// Add Binary
void test_addBinary();

int main ()
{
  test_addBinary();
  return 0;
}

void test_addBinary()
{
    string a = "1010";
    string b = "1011";
    string result = p3::addBinary(a, b);
    std::cout << "The sum binary string is: " << result << std::endl;
}