#ifndef CH3
#define CH3
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <list>
using namespace std;

namespace p3
{
    /*
        Algorithm Interface
    */
    bool isPalindrome(string s);
    //3.2: lcc28(实现 strStr())
    int strStr(const string& haystack, const string& needle);
    //3.3: lcc8(字符串转换整数 (atoi)
    int myAtoi(const string& str);
    //3.4 Add Binary: lcc67(二进制求和)
    string addBinary(string a, string b);
    //3.7 lcc44(通配符匹配)
    bool isMatch(string s, string p);
    bool isMatch_timeout(string s, string p);
    // lcc516(最长回文子序列)
    int longestPalindromeSubseq(string s);
};
#endif