#ifndef TREE_STRUCTURE
#define TREE_STRUCTURE
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace ts
{
    struct TreeNode 
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    //Recursion
    /*
     *1. 拆分成子问题, 注意, 子问题与原问题是等价的
     *2. pathFromNode求的是从根节点出发的路径, 注意, 这条路径不跨越根节点
     *3. 路径合并策略在longestUnivaluePath里
     * */
    class lc687//Longest Univalue Path
    {
        public:
            int longestUnivaluePath(TreeNode* root);
        private:
            int pathFromNode(TreeNode* root, int root_val);
    };
    
    //Binary search and Sorting
    class lc852//Peak Index in a Mountain Array
    {
        public:
            int peakIndexInMountainArray(vector<int>& A);
    };
    //Binary tree
    //Binary Search tree
}
#endif