#include "ch3.h"
using namespace std;

//3.5 longest palindromic substring
void test_longest_palindromic_substring();

int main ()
{
  test_longest_palindromic_substring();
  return 0;
}

void test_longest_palindromic_substring()
{
    //TODO
    string s = "aabbssb";
    p3::Solution so = p3::Solution();
    string res = so.longestPalindrome(s);
    std::cout << ">>>The original string is: " << s << std::endl;
    std::cout << "The palindromic string is: " << res << std::endl;
    
}