#ifndef CH5
#define CH5
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
#include <queue>
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
}
#endif
