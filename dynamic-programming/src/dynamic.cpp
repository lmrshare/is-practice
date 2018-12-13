#include "dynamic.h"

namespace dp
{
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
}
