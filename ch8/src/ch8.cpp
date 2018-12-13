#include "ch8.h"
#include <algorithm>

namespace p8
{
  vector<vector<int> > section_8_1_1::subsets(vector<int>& nums)
  {
#if 0
      return subsets(nums.begin(), nums.end());
#elif 1
      sort(nums.begin(), nums.end());
      return subsets(nums.begin(), nums.end());
#endif
  }
  vector<vector<int> > section_8_1_1::subsets(const vector<int>::iterator& begin,const vector<int>::iterator& end)
  {
#if 0
      if(begin == end) return vector<vector<int> >(0, vector<int>(0, 0));
      if(begin+1 == end) 
      {
          vector<vector<int> > res(0, vector<int>(0, 0));
          res.push_back(vector<int>(0, 0));
          res.push_back(vector<int>(1, *begin));
          return res;
      }
      vector<vector<int> > res(0, vector<int>(0, 0));
      int val = *begin;
      vector<vector<int> >res1 = subsets(begin+1, end);
      size_t num = res1.size();
      for(size_t i = 0; i < num; ++i)
      {
          vector<int> s = res1[i];
          s.push_back(val);
          res.push_back(s);
      }
      res.insert(res.end(), res1.begin(), res1.end());
      return res;
#elif 1
      if(begin == end) return vector<vector<int> >(0, vector<int>(0, 0));
      if(begin+1 == end) 
      {
          vector<vector<int> > res(0, vector<int>(0, 0));
          res.push_back(vector<int>(0, 0));
          res.push_back(vector<int>(1, *begin));
          return res;
      }
      vector<vector<int> > res(0, vector<int>(0, 0));
      int val = *begin;
      vector<vector<int> >res1 = subsets(begin+1, end);
      size_t num = res1.size();
      for(size_t i = 0; i < num; ++i)
      {
          vector<int> s = res1[i];
          if(val != *(begin+1))
          {
              s.push_back(val);
              res.push_back(s);
          }//duplicate element
          else
          {
              if(s.size() == (end-begin-1))
              {
                  s.push_back(val);
                  res.push_back(s);
              }
          }
      }
      res.insert(res.end(), res1.begin(), res1.end());
      vector<vector<int> > result(res.size());
      for(size_t i = 0; i < res.size();++i)
          result[i] = vector<int>(res[i].rbegin(), res[i].rend());
      return result;
#endif
  }

  vector<vector<int> > section_8_1_3::permute(vector<int> &num)
  {
      return permute(num.begin(), num.end());
  }
  vector<vector<int> > section_8_1_3::permute(const vector<int>::iterator& begin, const vector<int>::iterator& end)
  {
#if 0//permute
      if(begin == end) return vector<vector<int> >(0, vector<int>(0, 0));
      if(begin+1 == end) return vector<vector<int> >(1, vector<int>(1, *begin));
      vector<vector<int> > res(0, vector<int>(0, 0));
      int val = *begin;
      vector<vector<int> > res1 = permute(begin+1, end);
      for(auto v : res1)
      {
          for(int i = 0; i <= v.size();++i)
          {
              vector<int> v2(v.begin(), v.end());
              v2.insert(v2.begin()+i, val);
              res.push_back(v2);
          }
      }
      return res;
#elif 1
      if(begin == end) return vector<vector<int> >(0, vector<int>(0, 0));
      if(begin+1 == end) return vector<vector<int> >(1, vector<int>(1, *begin));
      vector<vector<int> > res(0, vector<int>(0, 0));
      int val = *begin;
      vector<vector<int> > res1 = permute(begin+1, end);
      for(auto v : res1)
      {
          auto it = find(v.begin(), v.end(), val);
          for(int i = 0; i <= v.size();++i)
          {
              vector<int> v2(v.begin(), v.end());
              if(it != v.end())//duplicate
              {
                if(v.begin()+i != it+1)
                {
                    v2.insert(v2.begin()+i, val);
                    res.push_back(v2);
                }
              }
              else
              {
                v2.insert(v2.begin()+i, val);
                res.push_back(v2);
              }
          }
      }
      return res;
#endif
  }

  vector<vector<int> > section_8_1_5::combine(int n, int k)
  {
      vector<int> values(n);
      iota(values.begin(), values.end(), 1);
      vector<bool> select(n, false);
      fill_n(select.begin(), k, true);
      vector<vector<int> > result;
      int flag = 1;
      do{
          ++flag;
        vector<int> one(k);
        for (int i = 0, index = 0; i < n; ++i)
            if (select[i])
                one[index++] = values[i];
        result.push_back(one);
      } while(prev_permutation(select.begin(), select.end()));
      return result;
  }

  void print_matrix(const vector<vector<int> >& M)
  {
      size_t rows = M.size();
      if(0 == rows)
      {
          cout << "[[]]" << endl;
          return;
      }
      cout << "[" << endl;
      for(size_t i = 0; i < rows; ++i)
      {
        size_t cols = M[i].size();
        if(0 == cols)
        {
            cout << "    [";
        }
        else
        {
            cout << "    [";
            for(size_t j = 0; j < cols; ++j) j != cols-1 ? cout << M[i][j] << "," : cout << M[i][j];
        }
        if(i != rows-1)
            cout << "]," << endl;
        else
            cout << "]" << endl;

      }
      cout << "]" << endl;
  }
}
