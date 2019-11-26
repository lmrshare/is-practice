#ifndef CH3
#define CH3
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <list>

using namespace std;

typedef string::const_iterator Iterator;
namespace std
{
    template<>
    struct hash<pair<Iterator, Iterator> >
    {
        size_t operator()(pair<Iterator, Iterator> const& p) const
        {
            return ((size_t) &(*p.first)) ^ ((size_t) &(*p.second));
        }
    };
};

namespace p3
{
    /*
        Structure 
    */
    struct random_list_node
    {
        int label;
        random_list_node* next;
        random_list_node* random;
        random_list_node(int label) : label(label), next(nullptr), random(nullptr) {};
    };
    struct list_node
    {
        int val;
        list_node* next;
        list_node(int x) : val(x), next(nullptr) {};
    };
    /*
        Algorithm Interface
    */
    //3.1: lcc125(验证回文串)
    bool isPalindrome(string s);
    //3.2: lcc28(实现 strStr())
    int strStr(const string& haystack, const string& needle);
    //3.3: lcc8(字符串转换整数 (atoi)
    int myAtoi(const string& str);
    //3.4 Add Binary: lcc67(二进制求和)
    string addBinary(string a, string b);
    //3.7 lcc44(通配符匹配)
    bool isMatch(string s, string p);
    //3.5 longest palindromic substring: lcc516(最长回文子序列)
    class Solution
    {
    public:
        string longestPalindrome(string s) {
            int len = s.length();
            //boundary treatment
            if(len == 1) return s;
            if(len == 2 && s[0] == s[1]) return s;
            else if(len == 2 && s[0] != s[1]) return "";
            string res = "";
            bool p[len][len];
            //initialize p
            for(int i = 0; i < len; ++i)
                for(int j = 0; j < len; ++j)
                {
                    if(j >= i && j-i <= 1) p[i][j] = true;
                    else p[i][j] = false;
                }
            //DP process
            for(int j = 2; j < len; ++j)
                for(int i = j-2; i>=0;--i)
                {
                    if(s[i] == s[j] && p[i+1][j-1] == true)
                    {
                        p[i][j] = true;
                        if(j-i+1 > res.length())res = s.substr(i, j-i+1);
                    }
                    else
                        p[i][j] = false;
                }
            return res;
        }
    private:
        unordered_map<pair<Iterator, Iterator>, string> cache;
        unordered_map<pair<string::const_iterator, string::const_iterator>, string>cache1;//not use, just for test
    };
};
#endif