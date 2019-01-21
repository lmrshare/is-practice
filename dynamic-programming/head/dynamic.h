#ifndef DYNAMIC_H
#define DYNAMIC_H
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std; 
namespace dp
{
    //tool function
    void print_vector(const vector<int>& nums);
    //Strategy/Solution Tree and Basic Dynamic Programming
    class lc338 //Counting Bits, bit manipulation
    {
        public:
            vector<int> countBits(int num);
    };
    class lc647 //Palindromic Substrings[考虑下怎么去除二维数组]
    {
        public:
            int countSubstrings(string s);
    };
    class lc120 //Triangle
    {
        public:
            int minimumTotal(vector<vector<int>>& triangle);            
    };
    class lc474 //Ones and Zeroes
    {
        public:
            int findMaxForm(vector<string>& strs, int m, int n);//mine
            int findMaxForm2(vector<string>& strs, int m, int n);//not mine(Greedy DP, beats 100%)
        int findMaxForm3(vector<string>& strs, int m, int n);//[TODO: 明天根据case理清楚里面]
        private:
            int findMaxForm(vector<string>& strs, int start, int m, int n);
            void zero_one_str(const string& str, int& zero_num, int& one_num);
    };
    class lcc5 //最长回文
    {
        public:
            string longestPalindrome(string s);//递归, 超出时间限制
            string longestPalindrome2(string s);//a. 非递归, 超出时间限制
            string longestPalindrome3(string s);//b. 非递归, 不用isPalindrome, ac
            /*
             *方案a和方案b其实差不多, 只不过把isPalindrome这个函数换掉, 用空间换时间, 把中间的是否为回文的判断结果存起来
             *
             * */
        private:
            string longestPalindrome(const string& s, int index);
            bool isPalindrome(const string& str);

    };
    class lccxxx //正则表达式匹配, 字符串、动态规划、回溯. TODO: 剩余: 把s长度为0的情况单独抽取出来处理
    {
        public:
            bool isMatch(const char *s, const char *p);
    };
    //Memorized Search
    //Advanced Dynamic Programming
    //Advanced Structure(e.g. Segment Tree, Binary Indexed Tree, etc)
    class lc121
    {
      public:
          int maxProfit(vector<int>& prices);
    };
    class lc53 
    {
      public:
          int maxSubArray(vector<int>& nums); 
    };
    class lc198
    {
      public:
          int rob(vector<int>& nums); 
    };
    class lcc53
    {
      public:
          int maxSubArray(vector<int>& nums); 
    };
    class lcc62
    {
      public:
          int uniquePaths(int m, int n);
    };
    class lcc63{
      public:
          int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid);
    };
    class lcc264
    {
        public:
          int nthUglyNumber(int n);
    };
    class lcc279
    {
        public:
          int numSquares(int n);
    };
    //执行用时: 16 ms, 在Longest Increasing Subsequence的C++提交中击败了72.86% 的用户
    class lcc300
    {
        public:
            int lengthOfLIS(vector<int>& nums);
    };
}
#endif
