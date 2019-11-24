#include "dynamic.h"
#include <algorithm>

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
    string lcc5::longestPalindrome(string s)
    {
        if(0 == s.size()) return "";
        if(1 == s.size()) return s;
        string str = longestPalindrome(s.substr(1, s.size()-1));
        string res; 
        if(s.substr(1, str.size()) == str)
        {
            size_t n = str.size();
            res = str.substr(0, n);
            for(size_t i = n+1; i <= s.size(); ++i)
                if(isPalindrome(s.substr(0, i)))
                    res = s.substr(0, i);
        }
        else
        {
            res = s.substr(0, 1);
            for(size_t i = 2; i <= s.size(); ++i)
                if(isPalindrome(s.substr(0, i)))
                    res = s.substr(0, i);
            if(res.size() < str.size())
                res = str;
        }
        return res;
    }
    string lcc5::longestPalindrome(const string& s, int index)
    {
        if(0 == s.size()) return "";
        if(1 == s.size()) return s;

    }
    bool lcc5::isPalindrome(const string& str)
    {
#if 0
        if(0 == str.size() || 1 == str.size()) return true;
        if(str[0] == str[str.size()-1] && isPalindrome(str.substr(1, str.size()-2)))
            return true;
        else
            return false;
#elif 1
        size_t n = str.size();
        for(size_t i = 0; i < n/2; ++i)
            if(str[i] != str[n-1-i])
                return false;
        return true;
#endif
    }
    string lcc5::longestPalindrome2(string s)
    {
        size_t n = s.size();
        if(0 == n || 1 == n) return s;
        string res(s.substr(n-1, 1));
        string fs;
        for(int i = n-1; i>=0; --i)
        {
            fs = s[i];
            for(int j = i+1; j < n; ++j)
                if(isPalindrome(s.substr(i, j-i+1)))
                    fs = s.substr(i, j-i+1);
            if(fs.size() > res.size())
                res = fs;
        }
        return res;
    }
    string lcc5::longestPalindrome3(string s)//非递归, 不用isPalindrome
    {
        size_t n = s.size();
        if(0 == n || 1 == n) return s;
        string res(s.substr(n-1, 1));
        string fs;
        vector<vector<bool> >P(n, vector<bool>(n, false));
        for(int i = n-1; i>=0; --i)
        {
            fs = s[i];
            P[i][i] = true;
            for(int j = i+1; j < n; ++j)
            {
                if(j == i+1 && s[j] == s[i] ||
                   s[j] == s[i] && P[i+1][j-1])
                {
                    fs = s.substr(i, j-i+1);
                    P[i][j] = true;
                    continue;
                }
            }
            if(fs.size() > res.size())
                res = fs;
        }
        return res;
    }   
    bool lccxxx::isMatch(const char *s, const char *p)
    {
        int ns = sizeof(s)/sizeof(char);
        int np = sizeof(p)/sizeof(char);
        if(0 == ns && 0 == np) return true;
        if(0 == np) return false;
        if(0 == ns)
        {
//            if(p[0])
        }
        const char *ss = s;
        const char *sp = p;
        for(const char *fp = p; fp < p+np; ++fp)
        {
            if(*fp == '.')
            {
                if(fp-sp+1 > s+ns-ss)
                    return false;
                while(sp != fp)
                    if(*sp++ != *ss++)
                        return false;
                ++ss;
            }
            else if(*fp == '*')
            {
                if(*sp != '*')//the first character is letter
                {
                    while(fp-sp > 1)
                    {
                        if(ss-s == ns) return false;
                        if(*sp++ != *ss++) return false;
                    }
                    //fp-sp == 1
                    if(ss-s ==ns || *sp != *ss)
                    {
                        //the case: [a, c*]
                        sp+=2;
                    }
                    else
                    {
                        //the case: [a, a*]
                        sp++;
                        ss++;
                        //then the case: [a, *]
                        const char *fs = ss;
                        while(fs+1-s < ns && *fs == *(fs+1))//all case
                        {
                            if(isMatch(fs+1, fp+1))return true;
                            fs++;
                        }
                        if(fs-s == ns) 
                        {

                        }
                        if(isMatch(fs+1, fp+1)) return true;
                    }
                }
                else//the first character is *, also means that sp == fp
                {
                     //then the case: [a, *]
                     const char *fs = ss;
                     while(*fs == *(fs+1))//all case
                     {
                         if(isMatch(fs+1, fp+1))return true;
                         fs++;
                     }
                     if(isMatch(fs+1, fp+1)) return true;
                }
            }
            else if(fp == p+np-1)
            {
                if(s+ns-1-ss != p+np-1-sp) return false;
                while(sp <= fp)
                    if(*sp++ != *ss++) return false;
            }
        }
        return false;
    }
    int lcc53::maxSubArray(vector<int>& nums)
    {
      size_t n = nums.size();
      if(n < 0) return 0;
      vector<int> s(n, 0);
      vector<int> p(n, 0);
      for(size_t i = 0; i < n; ++i)
      {
        if(0 == i)
        {
          s[i] = nums[i];
          p[i] = nums[i];
          continue;
        }
        s[i] = max(s[i-1]+nums[i], nums[i]);
        p[i] = max(s[i], p[i-1]);
      }
      return p[n-1];
    }
    int lcc62::uniquePaths(int m, int n)
    {
      if(0 == m || 0 == n) return 0;
      vector<int>dp(m, 1);
      for(int i = 1; i < n; ++i)
        for(int j = 1; j < m; ++j)
          dp[j] = dp[j] + dp[j-1];
      return dp[m-1];
    }
    int lcc63::uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
    {
      size_t m = obstacleGrid.size();
      if(0 == m) return 0;
      size_t n = obstacleGrid[0].size();
      if(0 == n) return 0;
      if(1 == obstacleGrid[0][0]) return 0;
      vector<vector<int> >dp(m, vector<int>(n, 0));
      for(size_t i = 0; i < n; ++i)
      {
        if(1 == obstacleGrid[0][i])
        {
          for(size_t j = i; j < n; ++j)
            dp[0][j] = 0;
          break;
        }
        else
          dp[0][i] = 1;
      }
      for(size_t i = 0; i < m; ++i)
      {
        if(1 == obstacleGrid[i][0])
        {
          for(size_t j = i; j < m; ++j)
            dp[j][0] = 0;
          break;
        }
        else
          dp[i][0] = 1;
      }

      for(size_t i = 1; i < m; ++i)
      {
        for(size_t j = 1; j < n; ++j)
        {
          if(1 == obstacleGrid[i][j])
            dp[i][j] = 0;
          else
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
      }
      return dp[m-1][n-1];
    }
    int lcc264::nthUglyNumber(int n)
    {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1]; 
    }
    int lcc279::numSquares(int n)
    {
        if(0 == n || 1 == n) return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i = 2; i<=n; ++i)
        {
            for(int j = 1; i-j*j>=0; ++j)
            {
                int tmp = 1 + dp[i - j*j];
                if(1 == j) dp[i] = tmp;
                if(tmp < dp[i]) dp[i] = tmp;
            }
        }
        return dp[n];
    }
    int lcc300::lengthOfLIS(vector<int>& nums)
    {
        if(0 == nums.size()) return 0;
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
        }
        int res = dp[0];
        for(int i = 1; i < nums.size();++i)
            if(dp[i] > res) res = dp[i];
        return res;
    }
    NumArray::NumArray(vector<int> nums)
    {
        sum.resize(nums.size()+1);
        sum[0] = 0;
        for(size_t i = 1; i < sum.size(); ++i)
            sum[i] = sum[i-1] + nums[i-1];
    }
    int NumArray::sumRange(int i, int j)
    {
        return sum[j+1]-sum[i];
    }
    NumMatrix::NumMatrix(vector<vector<int>> matrix)
    {
        sum.resize(matrix.size());
        int i = 0;
        for(auto v : matrix)
           sum[i++].resize(v.size()); 
        int sum_r;
        for(int i = 0; i < matrix.size(); ++i)
        {
            sum_r = 0;
            for(int j = 0; j < matrix[i].size(); ++j)
            {
                if(0 == j) sum_r = matrix[i][j];
                else sum_r += matrix[i][j];
                sum[i][j] = sum_r;
            }
        }
        for(int i = 1; i < sum.size(); ++i)
            for(int j = 0; j < sum[i].size(); ++j)
                if(j <= sum[i-1].size())
                    sum[i][j] += sum[i-1][j];

    }
    int NumMatrix::sumRegion(int row1, int col1, int row2, int col2)
    {
        row1--;
        col1--;
        if(row1 >=0 && col1 >= 0)
            return sum[row2][col2]-sum[row2][col1]-sum[row1][col2]+sum[row1][col1];
        else if(row1 < 0 && col1 >= 0)
            return sum[row2][col2]-sum[row2][col1];
        else if(row1 >=0 && col1 < 0)
            return sum[row2][col2]-sum[row1][col2];
        else
            return sum[row2][col2];
    }
}
