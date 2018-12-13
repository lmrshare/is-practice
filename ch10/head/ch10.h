#ifndef CH10
#define CH10
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace p10
{
  class section10_1
  {
    public:
      //n.n.n demo function
      vector<vector<string> > partition(string s);
    private:
      void dfs(string &s, vector<string>& path, vector<vector<string>> &result, size_t prev, size_t start);
      bool isPalindrome(const string &s, int start, int end);
  };
  class section10_4 
  {
     public:
      vector<vector<string>> solveNQueens(int n);
     private:
      void linesQueen(int n, vector<vector<int> >& path, vector<bool>& flags, vector<vector<string> >& res, int row, int col);
  };
  void print2Dvector(const vector<vector<std::string> >& M);
  void print2Dvector2(const vector<vector<std::string> >& M);
}
#endif
