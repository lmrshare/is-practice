#ifndef APRIL_ALGO
#define APRIL_ALGO
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <list>
using namespace std;

namespace april_algo
{
    /*
        Algorithm Interface
    */
    //3.3: lcc8(字符串转换整数 (atoi)
    int lengthOfLongestSubstring(string s);
    //暂时未分类
    int leastKMakeA_B_cntA_cntB(int a, int b, int cnta, int cntb);
};
#endif