#ifndef CHn
#define CHn
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace p7
{
  class section_7_1
  {
    public:
      //lcc715(Range 模块)
      vector<int> searchRange(vector<int>& nums, int target);
  };

  class section_7_2
  {
    public:
        //lcc35(搜索插入位置)
        int searchInsert(vector<int>& nums, int target);
  };

  class section_7_3
  {
    public:
        //lcc74(搜索二维矩阵)
        bool searchMatrix(vector<vector<int>>& matrix, int target);
  };
}
#endif
