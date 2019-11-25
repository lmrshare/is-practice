#include "ch3.h"
using namespace std;

//3.1
void test_isPalindrome();
//3.2
void test_strStr();
int strStr(const string& haystack, const string& needle);
//3.3
void test_myAtoi();
int myAtoi(const string& str);
//3.4 Add Binary
void test_addBinary();
string addBinary(string a, string b);
//3.5 longest palindromic substring
void test_longest_palindromic_substring();

//Wildcard Matching
bool isMatch(string s, string p);
void test_wildcard_matching();

int main ()
{
  test_isPalindrome();
  return 0;
}


void test_longest_palindromic_substring()
{
    //TODO
    string s = "aabbssb";
    p3::Solution so = p3::Solution();
    string res = so.longestPalindrome(s);
    std::cout << "The original string is: " << s << std::endl;
    std::cout << "The palindromic string is: " << res << std::endl;
    
}

void test_addBinary()
{
    string a = "1001";
    string b = "111";
    string result = p3::addBinary(a, b);
    std::cout << "The sum binary string is: " << result << std::endl;
}

void test_isPalindrome()
{
    string haystack = "A man, a plan, a canal: Panama";
    bool res = p3::isPalindrome(haystack);
    cout << "res: " << res << endl;
}
void test_strStr()
{
    string haystack = "hello the next task";
    string needle = "next";
    int pos = p3::strStr(haystack, needle);
    std::cout << "The position of needle is: " << pos << std::endl;
}

void test_myAtoi()
{
    string str = "1000";
    int value = p3::myAtoi(str);
    std::cout << "The str is: " << str << std::endl;
    std::cout << "The val is: " << value << std::endl;
}

void test_wildcard_matching()
{
    //TODO
}
