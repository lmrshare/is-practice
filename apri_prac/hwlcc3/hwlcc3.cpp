#include "april_algo.h"
using namespace std;

void test_lengthOfLongestSubstring();

int main ()
{
  test_lengthOfLongestSubstring();
  return 0;
}

void test_lengthOfLongestSubstring()
{
    string str = "2147483646";
    int value = april_algo::lengthOfLongestSubstring(str);
    cout << "value: " << value << endl;
}