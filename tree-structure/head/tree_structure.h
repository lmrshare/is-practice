#ifndef TREE_STRUCTURE
#define TREE_STRUCTURE
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
#include <map>
using namespace std;

namespace ts
{
    //tool function
    struct TreeNode; 
    void print_vector(vector<int>& nums);
    void print_tree(TreeNode *root);
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
    //Binary Search tree
    class lcc94
    {
        public:
           vector<int> inorderTraversal(TreeNode* root);
    };
    class lcc144
    {
        public:
           vector<int> preorderTraversal(TreeNode* root);
    };
    class lcc145
    {
        public:
            vector<int> postorderTraversal(TreeNode* root);
    };
    //tree, dynamiprogramming
    //执行用时: 12 ms, 在Unique Binary Search Trees II的C++提交中击败了99.47% 的用户
    class lcc95
    {
        public:
            vector<TreeNode*> generateTrees(int n);
        private:
            void gen_trees(TreeNode *root, int num, vector<TreeNode*>& trees);
    };
    //dynamic programming
    //执行用时: 0 ms, 在Unique Binary Search Trees的C++提交中击败了100.00% 的用户
    class lcc96
    {
        public:
           int numTrees(int n);
    };
    class lcc98
    {
        public:
            //执行用时: 8 ms, 在Validate Binary Search Tree的C++提交中击败了97.83% 的用户
            bool isValidBST(TreeNode* root);//后续遍历
            //执行用时: 8 ms, 在Validate Binary Search Tree的C++提交中击败了97.83% 的用户
            bool isValidBST2(TreeNode* root);//中序遍历
    };
    //执行用时: 8 ms, 在Validate Binary Search Tree的C++提交中击败了38.83% 的用户
    class lcc104
    {
        public:
            int maxDepth(TreeNode* root);
    };
    class lcc105
    {
        public:
            //执行用时: 12 ms, 在Construct Binary Tree from Preorder and Inorder Traversal的C++提交中击败了97.57% 的用户
            TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
        private:
            TreeNode* buildTree(vector<int>::iterator preb,
                                vector<int>::iterator pref,
                                vector<int>::iterator inb,
                                vector<int>::iterator inf,
                                map<int, int>& mpp,
                                map<int, int>& mpi,
                                vector<int>& preorder,
                                vector<int>& inorder
                                );
    };
    // not found in leetode until now.
    class left_view
    {
        public:
            vector<int> lv(TreeNode *root);
    };
    class right_view
    {
        public:
            vector<int> rv(TreeNode *root);
    };
    class all_leaf
    {
        public:
            vector<int> al(TreeNode *root);
    };
    //Binary tree
}
#endif
