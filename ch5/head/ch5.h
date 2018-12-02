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
            void preorder_traversal(const TreeNode* root);//recursion version
            void preorder_traversal_queue(const TreeNode* root);//queue version
        private:
            void preorder_recursion(const TreeNode* root);
    };
    class section5_1_2
    {
        public:
            void preorfer_inorder_traversal_stack(const TreeNode* root);
    };
    class section5_1_3
    {
        public:
            void postorder_inorder_traversal_stack(const TreeNode* root);
    };

    //skip residual of 5.1
    class section5_2_1
    {
        public:
            TreeNode* build_tree(vector<int>& preorder, vector<int>& inorder);
        private:
            TreeNode* build_tree(vector<int>::iterator pre_begin,
                                 vector<int>::iterator pre_end,
                                 vector<int>::iterator in_begin,
                                 vector<int>::iterator in_end
                                );
    };
    //skip residual of 5.2
    class section5_3_1
    {
        public:
            int numTrees(int n);
    };
}
#endif
