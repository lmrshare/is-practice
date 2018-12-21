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
  int lc647::countSubstrings(string s)
  {
      size_t n = s.size();
      if(1 == n) return 1;
      if(0 == n) return 0;
      int res = n;
      vector<vector<bool> > P(n-1, vector<bool>(n, false));
      for(int i = n-2; i >= 0; --i)
      {
          for(int j = i; j < n; ++j)
          {
              if(i == j)
              {
                  P[i][i] = true;
                  continue;
              }
              if(s[i] == s[j] && (i+1 == j || P[i+1][j-1]))
              {
                  res += 1;
                  P[i][j] = true;
              }
          }
      }
      return res;
  }
  int lc120::minimumTotal(vector<vector<int> >& triangle)
  {
      size_t n = triangle.size();
      if(0 == n) return 0;
      if(1 == n) return triangle[0][0];
      for(int i = n-2; i >= 0; --i)
          for(int j = 0; j < triangle[i].size(); ++j)
              triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
      return triangle[0][0];
  }
  int lc474::findMaxForm(vector<string>& strs, int m, int n)
  {
      size_t num = strs.size();
      if(0 == num) return 0;
      if(1 == num)
      {
          int zero_num, one_num;
          zero_one_str(strs[0], zero_num, one_num);
          if(m == zero_num && n == one_num) return 1;//ok
          else return 0;//no
      }
      sort(strs.begin(), strs.end(), [n,m] (string a, string b){
          if (a.size() != b.size()) return a.size() < b.size();
          return (m <= n) ? a < b : b > a;
      });
      return findMaxForm(strs, 0, m, n);
  }
  int lc474::findMaxForm(vector<string>& strs, int start, int m, int n)
  {
      //terminal condition
      if(start >= strs.size()) return 0;
      int zero_num, one_num;
      zero_one_str(strs[start], zero_num, one_num);
      //pruning
      if(zero_num > m || one_num > n)
          return findMaxForm(strs, start+1, m, n);
      else
          return max(
                    1+findMaxForm(strs, start+1, m-zero_num, n-one_num),
                    findMaxForm(strs, start+1, m, n)
                );
  }
  void lc474::zero_one_str(const string& str, int& zero_num, int& one_num)
  {
      zero_num = 0;
      one_num = 0;
      for(const auto & c : str)
      {
          if(0 == c-'0')
              zero_num++;
          if(1 == c-'0')
              one_num++;
      }
  }
  int lc474::findMaxForm2(vector<string>& sv, int m, int n) 
  {
      int l = sv.size();
      if (!l)
      {
          return 0;
      }
      sort(sv.begin(), sv.end(), [n,m] (string a, string b){
          if (a.size() != b.size()) return a.size() < b.size();
          return (m <= n) ? a < b : b > a;
      });
      
      vector<pair<int, pair<int, int> > > dp(l + 1);
      dp[0] = {0, {0, 0}};
      for (int i = 1; i <= l; ++i)
      {
          int z = 0, o = 0;
          for (auto& c: sv[i - 1])
          {
              z += (c == '0');
              o += (c == '1');
          }
          dp[i] = dp[i - 1];
          for (int j = 0; j < i; ++j)
          {
              if (dp[j].first + 1 > dp[i].first &&
                  dp[j].second.first + z <= m &&
                  dp[j].second.second + o <= n)
              {
                  dp[i].first = dp[j].first + 1;
                  dp[i].second = {dp[j].second.first + z, dp[j].second.second + o};
              }
              else if (dp[j].first + 1 == dp[i].first &&
                       (
                        (dp[j].second.first + z < dp[i].second.first && dp[j].second.second + o <= n )||
                        (dp[j].second.second + o < dp[i].second.second && dp[j].second.first + z <= m)
                        )
                       )
              {
                  dp[i].second = {dp[j].second.first + z, dp[j].second.second + o};
              }
          }
      }
      
      int ans = 0;
      for (int i = 1; i <= l; ++i)
      {
          ans = max(dp[i].first, ans);
      }
      
      return ans;
   }
    int lc474::findMaxForm3(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int zeros = 0, ones = 0;
            for (char c : str) (c == '0') ? ++zeros : ++ones;
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
}
