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
    string haystack = "A man, a plan, a canal: Panama";
    bool res = p3::isPalindrome(haystack);
    cout << "res: " << res << endl;
}