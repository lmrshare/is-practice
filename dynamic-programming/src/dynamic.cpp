#include "dynamic.h"

namespace dp
{
  void print_vector(const vector<int>& nums)
  {
      cout << "[";
      for(auto & num : nums)
          cout << num << " , ";
      cout << "]\n";
  }
  int lc121::maxProfit(vector<int>& prices)
  {
      size_t n = prices.size();
      if(n <= 1) return 0;
      int res = 0;
      int max_subarray = prices[n-2];
      if(prices[n-1] > prices[n-2])
      {
          res = prices[n-1] - prices[n-2];
          max_subarray = prices[n-1];
      }
      if(n == 2) return res;
      for(int i = n-2; i >= 0; --i)
      {
          int res2 = 0;
          if(max_subarray > prices[i])
              res2 = max_subarray - prices[i];
          else
              max_subarray = prices[i];
          if(res2 > res)
              res = res2;
      }
      return res;
  }
  int lc53::maxSubArray(vector<int>& nums)
  {
      size_t n = nums.size();
      if(n == 0) return 0;
      if(n == 1) return nums[0];
      int f_maxsum = nums[n-1];
      int maxsum = nums[n-1];
      for(int i = n-2; i >= 0; --i)
      {
          int tmp = f_maxsum + nums[i];
          if( tmp > maxsum)
              maxsum = tmp;
          if(tmp < nums[i])
              f_maxsum = nums[i];
          else
              f_maxsum = tmp;
      }
      return maxsum;
  }
  int lc198::rob(vector<int>& nums)
  {
      size_t n = nums.size();
      if(n == 0) return 0;
      if(n == 1) return nums[0];
      int fn = nums[n-1];
      int fn_1 = nums[n-2];
      if(n == 2)
          if(fn > fn_1) return fn;
          else return fn_1;
      int fi = 0;
      for(int i = n-3; i >=0; --i)
      {
          if(fn_1 > fn + nums[i]) fi = fn_1;
          else fi = fn + nums[i];
          fn = fn_1;
          fn_1 = fi;
      }
      return fi;
  }
  vector<int> lc338::countBits(int num)
  {
      vector<int> res(num+1, 0);
      size_t len = sizeof(int) * 8;
      for(int i = 1; i <= num; ++i)
      {
          if(0 == i % 2)
          {
#if 0
              for(size_t j = 0; j< len; ++j)
                  res[i] += i >> j & 1;
#elif 1
              res[i] = res[i>>1];//偶数的最后一位一定为0，所以右移一位没影响
#endif
          }
          else
              res[i] = res[i-1] + 1;
      }
      return res;
  }
}
