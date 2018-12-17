#ifndef DYNAMIC_H
#define DYNAMIC_H
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace dp
{
    //tool function
    void print_vector(const vector<int>& nums);
    //Strategy/Solution Tree and Basic Dynamic Programming
    class lc338 //Counting Bits, bit manipulation
    {
        public:
            vector<int> countBits(int num);
    };
    //Memorized Search
    //Advanced Dynamic Programming
    //Advanced Structure(e.g. Segment Tree, Binary Indexed Tree, etc)
    class lc121
    {
      public:
          int maxProfit(vector<int>& prices);
    };
    class lc53 
    {
      public:
          int maxSubArray(vector<int>& nums); 
    };
    class lc198
    {
      public:
          int rob(vector<int>& nums); 
    };
}
#endif
