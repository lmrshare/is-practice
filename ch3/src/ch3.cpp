#include "ch3.h"
#include <algorithm>
#include <numeric>
#include <assert.h>
#include <iostream>
#include <climits>
using namespace std;

namespace p3{
    //计算进位和当前值
    string addBinary(string a, string b)
    {
        string result;
        int n = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.begin());
        reverse(b.begin(), b.begin());
        int carry = 0;
        for(int i = 0; i < n; ++i)
        {
            const int ai = i < a.size() ? a[i] - '0' : 0;
            const int bi = i < b.size() ? b[i] - '0' : 0;
            const int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) /2;
            result.insert(result.begin(), val + '0');
        }
        if(carry == 1)
            result.insert(result.begin(), '1');
        return result;
    }

    int strStr(const string& haystack, const string& needle)
    {
        if(needle.empty()) return 0;
        const int N = haystack.size() - needle.size();
        for(int i = 0; i < N; ++i)
        {
            int j = i;
            int k = 0;
            //while( j < haystack.size() &&k < needle.size() && haystack[j] == needle[k])
            while( k < needle.size() && haystack[j] == needle[k])
            {
                j++;
                k++;
            }
            if(k == needle.size()) return i;
        }
        return -1;
    }
    
    int myAtoi(const string& str)
    {
        int val = 0;
        int sign = 1;
        const int num = str.length();
        int i = 0;
        while(str[i] == ' ' && i < num) i++;
        if(str[i] == '-')
        {
            i++;
            sign = -1;
        }
        else if(str[i] == '+')
            i++;
        for(; i < num; i++)
        {
            if(str[i] < '0' || str[i] > '9')
                break;
            if(val > INT_MAX / 10 || (val == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
                return sign == -1 ? INT_MIN : INT_MAX;
            val = val * 10 + str[i] - '0';
        }
        return val * sign;
    }
    
    bool isMatch(string s, string p)
    {
#if 0//没做完
        int len_s = s.length();
        int len_p = p.length();
        if(len_s == 0)
        {
            if(len_P == 0) return true;
            else if(len_p == 1 && p[0] == '*') return true;
            else if(p[len_p-1] == '*') return isMatch(s, s.substr(0, len_p-1));
            {
                if(p[len_p - 1] ==)
                    }
        }
        else
        {
            
        }
        
#endif
    }
    
};
