#include "ch10.h"

namespace p10
{
  vector<vector<string> > section10_1::partition(string s)
  {
      vector<vector<string>> result;
      vector<string> path;
      dfs(s, path, result, 0, 1);
      return result;  
  }
  void section10_1::dfs(string &s, vector<string>& path, vector<vector<string>> &result, size_t prev, size_t start)
  {
      if (start == s.size()) 
      {
          if (isPalindrome(s, prev, start - 1)) 
          {
            path.push_back(s.substr(prev, start - prev));
            result.push_back(path);
            path.pop_back();
          }
          return;
      }
      dfs(s, path, result, prev, start + 1);
      if (isPalindrome(s, prev, start - 1)) 
      {
          path.push_back(s.substr(prev, start - prev));
          dfs(s, path, result, start, start + 1);
          path.pop_back();
      }

  }
  bool section10_1::isPalindrome(const string &s, int start, int end) 
  {
      while (start < end && s[start] == s[end]) 
      {
          ++start;
          --end;
      }
      return start >= end;
  }
  vector<vector<string>> section10_4::solveNQueens(int n)
  {
      vector<vector<string> > res(0, vector<string>(0, ""));
      vector<vector<int> > path(0, vector<int>(0, 0));
      vector<bool> flags(n, true);
      
      for(int i = 0; i < n; ++i)
      {
        linesQueen(n, path, flags, res, 0, i);
        path.clear();
      }
      return res;
  }
  void section10_4::linesQueen(int n, vector<vector<int> >& path, vector<bool>& flags, vector<vector<string> >& res, int row, int col)
  {
      if(row < n)
      {
          if(!flags[col]) return;
          path.push_back(vector<int>{row, col});
          for(auto  flag : flags) flag = true;
          for(auto & pos : path)
          {
              flags[pos[1]] = false;
              if(pos[0] == row && pos[1] == col)
              {
                  if(col - 1 >= 0)
                    flags[col - 1] = false;
                  if(col + 1 < n)
                    flags[col + 1] = false;
              }
          }
      }
      if(row == n)
      {
          vector<string> r(n, string(n, '.'));
          if(path.size() > 0)
          {
              for(auto & pos : path)
              {
                  r[pos[0]][pos[1]] = 'Q';
              }
              res.push_back(r);
          }
          for(auto flag : flags) flag = true;
          for(auto & pos : path) flags[pos[1]] = false;
          path.pop_back();
          return;
      }
      for(int i = 0; i < n; ++i)
      {
          linesQueen(n, path, flags, res, row+1, i);
          if(path.size() < n)
          {
              if(i == n-1 && path.size() < row+2)//说明一整行都没有合适的，说明上一行的位置不对
              {
                  path.pop_back();
                  for(auto  flag : flags) flag = true;
                  for(auto & pos : path)
                  {
                      flags[pos[1]] = false;
                      if(pos[0] == path[row-1][0] && pos[1] == path[row-1][1])
                      {
                          if(col - 1 >= 0)
                              flags[col - 1] = false;
                          if(col + 1 < n)
                              flags[col + 1] = false;
                      }
                  }
              }
              continue;
          }
          break;
      }

  }
  void print2Dvector(const vector<vector<std::string> >& M)
  {
      for(auto & row : M)
      {
          std::cout << "[";
          for(auto & s : row)
              std::cout << s << " ";
          std::cout << "]" << std::endl;
      }
  }
  void print2Dvector2(const vector<vector<std::string> >& M)
  {
     for(auto & row : M)
      {
          std::cout << "[" << std::endl;
          for(auto & s : row)
              std::cout << s << std::endl;
          std::cout << "]" << std::endl;
      }

  }

}
