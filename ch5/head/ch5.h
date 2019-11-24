#ifndef CH5
#define CH5
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

namespace p5
{
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    };
    class section5_1_1
    {
        public:
            //lcc889(根据前序和后序遍历构造二叉树)
            void preorder_traversal(const TreeNode* root);//recursion version
            void preorder_traversal_queue(const TreeNode* root);//queue version
        private:
            void preorder_recursion(const TreeNode* root);
    };
    class section5_1_2
    {
        public:
            //lcc94(二叉树的中序遍历)
            void preorfer_inorder_traversal_stack(const TreeNode* root);
    };
    class section5_1_3
    {
        public:
            //lcc106(从中序与后序遍历序列构造二叉树)
            void postorder_inorder_traversal_stack(const TreeNode* root);
    };

    //skip residual of 5.1
    class section5_2_1
    {
        public:
            //lcc105(从前序与中序遍历序列构造二叉树)
            TreeNode* build_tree(vector<int>& preorder, vector<int>& inorder);
        private:
            TreeNode* build_tree(vector<int>::iterator pre_begin,
                                 vector<int>::iterator pre_end,
                                 vector<int>::iterator in_begin,
                                 vector<int>::iterator in_end
                                );
    };
    //skip residual of 5.2; lcc95(不同的二叉搜索树2)
    class section5_3_1
    {
        public:
            int numTrees(int n);
    };
}
#endif
