#include "ch5.h"

namespace p5
{
    void section5_1_1::preorder_recursion(const TreeNode* root)
    {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr)
        {
            cout << root->val;
            return;
        }
        cout << root->val;
        if(root->left != nullptr)
        {
            cout << ", ";
            preorder_recursion(root->left);
        }
        if(root->right != nullptr)
        {
            cout << ", ";
            preorder_recursion(root->right);
        }
    }
    void section5_1_1::preorder_traversal(const TreeNode* root)
    {
        cout << "[";
        preorder_recursion(root);
        cout << "]" << endl;
    }
    void section5_1_1::preorder_traversal_queue(const TreeNode* root)
    {
        if(root == nullptr) 
        {
            cout << "[]";
            return;
        }
        cout << "[";
        queue<TreeNode*> q;
        TreeNode *tmp = new TreeNode(root->val);
        tmp->left = root->left;
        tmp->right = root->right;
        q.push(tmp);
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if(node != nullptr)
            {
                cout << node->val;
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
                if(!q.empty()) cout << ", ";
            }

        }
        cout << "]" << endl;
    }
    void section5_1_2::preorfer_inorder_traversal_stack(const TreeNode* root)
    {
        if(root == nullptr)
        {
            cout << "[]";
            return;
        }
        cout << "[";
        stack<const TreeNode*> q;
        const TreeNode *p = root;
        while(!q.empty() || p != nullptr)
        {
            if(p != nullptr)
            {
                q.push(p);
                p = p->left;
            }
            else
            {
                //p = q.front();
                p = q.top();
                q.pop();
                cout << p->val;
                p = p->right;
            }
        }
        cout << "]" << endl;
    }
    void section5_1_3::postorder_inorder_traversal_stack(const TreeNode* root)
    {
        cout << "TODO" << endl;
    }
    TreeNode* section5_2_1::build_tree(vector<int>& preorder, vector<int>& inorder)
    {
        return build_tree(preorder.begin(),
                          preorder.end()-1,
                          inorder.begin(),
                          inorder.end()-1
                         );
    }
    TreeNode* section5_2_1::build_tree(vector<int>::iterator pre_begin,
                         vector<int>::iterator pre_end,
                         vector<int>::iterator in_begin,
                         vector<int>::iterator in_end
                         )
    {
        TreeNode *root = nullptr;
        if(pre_begin == pre_end)
        {
            root = new struct TreeNode(*pre_begin);
            return root;
        }
        vector<int>::iterator it = find(in_begin, in_end, *pre_begin);
        if(*pre_begin == *it)
            root = new struct TreeNode(*it);
        else
            return root;
        int l_num = it - in_begin;//left tree
        int r_num = in_end - it;//right tree
        TreeNode *left_tree = build_tree(pre_begin+1,
                                         pre_begin+l_num,
                                         in_begin,
                                         it-1);
        TreeNode *right_tree = build_tree(pre_end-r_num+1,
                                          pre_end,
                                          it+1,
                                          in_end);
        root->left = left_tree;
        root->right = right_tree;
        return root;
    }
    //卡塔兰数
    int section5_3_1::numTrees(int n)
    {
        vector<int> C(n + 1, 0);
        C[0] = 1;
        if(n >= 1) C[1] = 1;
        for(int i = 2; i <= n; ++i)
            for(int j = 0; j < i; ++j)
                C[i] += C[j] * C[i - 1 - j];
        return C[n];
    }
}
