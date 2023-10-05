#include "ch3.h"
#include <algorithm>
#include <numeric>
#include <assert.h>
#include <climits>

namespace p3
{
    bool isPalindrome(string s)
    {
        size_t num = s.size();
        if (num == 0)
            return true;
        int i = 0;
        int j = num-1;
        bool res = true;
        while(i <= j)
        {
            if ((s[i] < '0' || s[i] > '9') &&
                (s[i] < 'a' || s[i] > 'z') &&
               (s[i] < 'A' || s[i] > 'Z'))
             {
                 i++;
                 continue;
             }
            if ((s[j] < '0' || s[j] > '9') &&
                (s[j] < 'a' || s[j] > 'z') &&
               (s[j] < 'A' || s[j] > 'Z'))
             {
                 j--;
                 continue;
             }
             if (s[i] >= '0' && s[i] <= '9')
             {
                 if (s[i] != s[j])
                 {
                     res = false;
                     break;
                 }
             }
             else if (s[i] >= 'a' && s[i] <= 'z')
             {
                 if (s[j] >= 'a' && s[j] <= 'z' && s[i] != s[j])
                 {
                     res = false;
                     break;
                 }
                 else if (s[j] >= 'A' && s[j] <= 'Z' && s[i]-'a' != s[j]-'A')
                 {
                     res = false;
                     break;
                 }
                 else if (s[j] >= '0' && s[j] <= '9')
                 {
                     res = false;
                     break;
                 }
             }
             else
             {
                 if (s[j] >= 'a' && s[j] <= 'z' && s[i]-'A' != s[j]-'a')
                 {
                     res = false;
                     break;
                 }
                 else if (s[j] >= 'A' && s[j] <= 'Z' && s[i] != s[j])
                 {
                     res = false;
                     break;
                 }
                 else if (s[j] >= '0' && s[j] <= '9')
                 {
                     res = false;
                     break;
                 }
             }
             i++;
             j--;
        }
        return res;
    }
    //计算进位和当前值
    string addBinary(string a, string b)
    {
        string result;
        int n = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
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
        long val = 0;
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
    
    /* 超时 */
    bool isMatch_timeout(string s, string p)
    {
        size_t s_len = s.size();
        size_t p_len = p.size();
        if (s_len != 0 && p_len == 0)
            return false;
        if (s_len == 0 && p_len == 0)
            return true;
        if (p[0] >= 'a' && p[0] <= 'z')
        {
            if (s_len == 0)
                return false;
            if (p[0] == s[0])
                return isMatch(s.substr(1, s_len-1), p.substr(1, p_len-1));
            else
                return false;
        }
        else if (p[0] == '?')
        {
            if (s_len == 0)
                return false;
            return isMatch(s.substr(1, s_len-1), p.substr(1, p_len-1));
        }
        else
        {
            if (s_len == 0)
            {
                if (p_len > 1 && p[1] != '*')
                    return false;
                if (p_len > 1 && p[1] == '*')
                    return isMatch(s, p.substr(2, p_len-2));
                return true;
            }
            if (p_len == 1)
                return true;
            else if (p[1] >= 'a' && p[1] <= 'z')
            {
                for (size_t i = 0; i < s_len; ++i)
                {
                    if (s[i] == p[1])
                    {
                        if (isMatch(s.substr(i+1, s_len-i), p.substr(2, p_len-2)))
                            return true;
                        else
                            continue;
                    }
                }
                return false;
            }
            else if (p[1] == '?')
            {
                for (size_t i = 0; i < s_len; ++i)
                {
                    if (isMatch(s.substr(i+1, s_len-i), p.substr(2, p_len-2)))
                        return true;
                    else
                        continue;
                }
                return false;
            }
            else
                return isMatch(s, p.substr(1, p_len-1));
        }
    }

    bool isMatch(string s, string p)
    {
        size_t s_len = s.size();
        size_t p_len = p.size();
        bool dp[p_len+1][s_len+1];
        dp[0][0] = true;
        for (size_t i =1; i <= s_len; ++i)
            dp[0][i] = false;
        for (size_t j = 1; j <= p_len; ++j)
        {
            for (size_t i = 0; i <= s_len; ++i)
            {
                if (i == 0)
                {
                    if (p[j-1] != '*')
                        dp[j][i] = false;
                    else
                        dp[j][i] = dp[j-1][i];
                }
                else
                {
                    if (p[j-1] >= 'a' && p[j-1] <= 'z')
                    {
                        dp[j][i] = p[j-1] == s[i-1] && dp[j-1][i-1];
                    }
                    else if (p[j-1] == '?')
                        dp[j][i] =  dp[j-1][i-1];
                    else
                    {
                        dp[j][i] = false;
                        if (dp[j][i-1] || dp[j-1][i-1] || dp[j-1][i])
                            dp[j][i] = true;
                    }
                }
            }
        }
        return dp[p_len][s_len];
    }
    bool isPalindrome(string str, char c)
    {
        return true;
    }

    int longestPalindromeSubseq(string s)
    {
        size_t N = s.size();
        if (N == 0)
            return 0;
        int dp[N][N];
        for (size_t i = 0; i < N; ++i)
            dp[i][i] = 1;
        for (int i = N-1; i>=0; --i)
        {
            for (int j = i+1; j < N; ++j)
            {
                if (s[i] == s[j])
                {
                    if (j == i+1)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = dp[i+1][j-1] + 2;
                }
                else
                {
                    if (j == i+1)
                    {
                        dp[i][j] = 1;
                        continue;
                    }
                    dp[i][j] = dp[i][j-1];
                    if (dp[i][j] < dp[i+1][j])
                        dp[i][j] = dp[i+1][j];
                }
                
            }
        }
        return dp[0][N-1];
    }

    int candy(vector<int>& ratings)
    {
        if (ratings.size() == 1)
            return 1;
        if (ratings.size() == 0)
            return 0;
        vector<int> candies(ratings.size(), 1);
        int min_nums = ratings.size();
        for (int i = 0;  i <= ratings.size()-2; ++i)
        {
            //cout << ">>>i: " << i <<", ratings.eize(): " << ratings.size() << endl;
            if ((ratings[i] > ratings[i+1]) &&
                (candies[i] == candies[i+1]))
            {
                candies[i]++;
                min_nums++;
                continue;
            }
            if ((ratings[i] < ratings[i+1]) &&
                (candies[i] >= candies[i+1]))
            {
                int delta = candies[i] - candies[i+1] + 1;
                candies[i+1] +=  delta;
                min_nums += delta;
                continue;
            }
        }
        for (int i = ratings.size()-1;  i > 0 ; --i)
        {
            if ((ratings[i] < ratings[i-1]) &&
                (candies[i] >= candies[i-1]))
            {
                int delta = candies[i] - candies[i-1] + 1;
                candies[i-1] +=  delta;
                min_nums += delta;
                continue;
            }
        }
        for (int i = 0;  i <= candies.size()-1; ++i)
        {
            cout << "candies[" << i <<"]: " << candies[i] << endl;
        }
        return min_nums;
    }
};
