#include "ch7.h"

namespace p7
{
  vector<int> section_7_1::searchRange(vector<int>& nums, int target)
  {
      vector<int> res(0);
      int len = nums.size();
      if(len == 0 || len == 1 && nums[0] != target)
      {
          res.push_back(-1);
          res.push_back(-1);
      }
      int s = 0, f = len-1;
      while(s <= f)
      {
          int mid = (s + f)/2;
          if(nums[mid] == target)
          {
              s = f = mid;
              for(; s-1>= 0 && nums[s-1] == target; --s);
              for(; f+1 < len && nums[f+1] == target; ++f);
              break;
          }
          else if(nums[mid] > target) f -= 1;
          else s += 1;
      }
      res.push_back(s);
      res.push_back(f);
      return res;
  }
  int section_7_2::searchInsert(vector<int>& nums, int target)
  {
      //这道题主要是分析while循环下的边界部分，我的思路是：当代码走到12的时候s，f，mid是一种什么状态，然后来处理.
      size_t len = nums.size();
      if(0 == len) return 0;
      int s = 0, f = len-1;
      int mid = 0;
      while(s < f)
      {
          mid = (s+f)/2;
          if(nums[mid] == target) return mid;
          else if(nums[mid] > target) f -= 1;
          else s += 1;
      }
      if(target < nums[f]) return s;
      else return s+1;
  }
  bool  section_7_3::searchMatrix(vector<vector<int>>& matrix, int target)
  {
      //注意分析边界情况, f是有可能没比较的, 所以最后一波要判断一下
      size_t m = matrix.size();
      size_t n = matrix.front().size();
      size_t s = 0, f = m * n - 1;
      while(s < f)
      {
          size_t mid = (s + f)/2;
          size_t r = (mid + 1)/n - 1, c = (mid + 1)%n - 1;
          if(matrix[r][c] == target) return true;
          else if(matrix[r][c] > target) f = mid - 1;
          else s = mid + 1;
      }
      return target == matrix[(f+1)/n - 1][(f+1)%n -1];
  }

}
