#ifndef BIT_OPERATION
#define BIT_OPERATION
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace bo
{
  class lcc136//只出现一次的数字
  {
    public:
      int singleNumber(vector<int>& nums);
  };
  class lcc137//只出现一次的数字 II, 统计每一位1的个数, 看是否可以对3整除
  {
      public:
          int singleNumber(vector<int>& nums);
  };
  class lcc169//求众数
  {
      public:
          int majorityElement(vector<int>& nums);//hash table version
          int majorityElement2(vector<int>& nums);//quick sort version
      private:
          void quicksort(vector<int>& nums, int p, int r);//Recursion version
          void quicksort(vector<int>& nums);//Non-recursion version
          int partion(vector<int>& nums, int p, int r);
          int partion2(vector<int>& nums, int start, int end);//for non-recursion version
  };
}
#endif
