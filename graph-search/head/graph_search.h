#ifndef GS
#define GS
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace gs
{
    class Node
    {
        public:
            int val;
            vector<Node*> children;

            Node() {}
            Node(int _val, vector<Node*> _children) 
            {
                val = _val;
                children = _children;
            }
    };
    struct State
    {
        Node *node;
        int chid;
        State():node(nullptr), chid(0){}
        State(Node *node_): node(node_), chid(0){}
    };
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    struct State2
    {
        TreeNode *node;
        int  next;
        State2(TreeNode *node_, int next_): node(node_), next(next_) {}
    };
    struct UndirectedGraphNode
    {
        int label;
        vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) : label(x) {};
    };
    //Depth First Search
    class lc559//Maximum Depth of N-ary Tree
    {
        public:
            int maxDepth(Node* root);//recursion dfs
            int maxDepth2(Node* root);//dfs, non-recursion(faster than recursion dfs)
    };
    class lcc329 //[TODO]矩阵中的最长递增路径, hard[dfs, 拓扑排序, 记忆化]
    {
        public:
            int longestIncreasingPath(vector<vector<int>>& matrix);

    };
    //Breadth Fitst Search
    class lc513 //Find Bottom Left Tree Value
    {
        public:
            int findBottomLeftValue(TreeNode* root);
    };
    class lcc133//克隆图
    {
        public:
            UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node);
    };
    class clonetree
    {
        public:
            TreeNode* cloneTree(TreeNode* root);
    };
    //Dijkstra's algorithm(Best First Search)
    //Union Find
}
#endif
