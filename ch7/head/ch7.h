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
      vector<int> searchRange(vector<int>& nums, int target);
  };

  class section_7_2
  {
    public:
        int searchInsert(vector<int>& nums, int target);
  };

  class section_7_3 
  {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target);
  };
}
#endif
