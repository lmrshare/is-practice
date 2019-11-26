#include "ch3.h"
using namespace std;

void test_isPalindrome();

int main ()
{
  test_isPalindrome();
  return 0;
}

void test_isPalindrome()
{
    //string haystack = "A man, a plan, a canal: Panama";
    //string haystack = "race a car";
    //string haystack = "ab2a";
    string haystack = "0z;z   ; 0";
    bool res = p3::isPalindrome(haystack);
    cout << "res: " << boolalpha << res << endl;
}