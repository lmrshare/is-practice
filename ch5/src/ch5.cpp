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
}
