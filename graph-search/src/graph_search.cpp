#include "graph_search.h"
#include <stack>
namespace gs
{
    int lc559::maxDepth(Node* root)
    {
        if(nullptr == root) return 0;
        size_t n = root->children.size();
        if(0 == n) return 1;
        int deep = 0;
        for(size_t i = 0; i < n; ++i)
            deep = max(deep, maxDepth(root->children[i]));
        return deep+1;
    }
    int lc559::maxDepth2(Node* root)//dfs, non-recursion
    {
        if(nullptr == root) return 0;
        stack<State*> q;
        q.push(new State(root));
        int deep = 1;
        int max_deep = 1;
        while(!q.empty())
        {
            State *s = q.top();
            q.pop();
            if(0 == s->node->children.size())//leaf
            {
                if(deep > max_deep) max_deep = deep;
                --deep;
                continue;
            }
            if(s->chid == s->node->children.size())//there is no child more, for binary tree, just according to right child
            {
                --deep;
                continue;
            }
            s->chid++;//point to next child
            q.push(s);//push s again
            q.push(new State(s->node->children[s->chid-1]));//push th child
            ++deep;
        }
        return max_deep;
    }
    int lc513::findBottomLeftValue(TreeNode* root)
    {
        if(nullptr == root->left && nullptr == root->right)
            return root->val;
        stack<State2*> q;
        q.push(new State2(root, 0));
        int dl = root->val;
        int deep = 1;
        int max_deep = 1;
        while(!q.empty())
        {
            State2 *s = q.top();
            q.pop();
            if(nullptr == s->node->left &&
                    nullptr == s->node->right)//leaf
            {
//                if(deep > max_deep || deep == max_deep &&
//                   q.top()->node->left == s->node)
                if(deep > max_deep)
                {
                    dl = s->node->val;
                    max_deep = deep;
                }
                    --deep;
                    continue;
            }
            if(2 == s->next)//there is no child left
            {
                --deep;
                continue;
            }
            if(0 == s->next)
            {
                if(nullptr != s->node->left)
                {
                    s->next = 1;
                    q.push(s);//push again
                    q.push(new State2(s->node->left, 0));//push left
                    deep++;
                }
                else
                {
                    s->next = 2;
                    q.push(s);
                    q.push(new State2(s->node->right, 0));//push left
                    deep++;
                }
                    continue;
            }
            else if(1 == s->next)
            {
                s->next = 2;
                if(nullptr != s->node->right)
                {
                    q.push(s);
                    q.push(new State2(s->node->right, 0));
                    deep++;
                    continue;
                }
                else
                {
                    s->next = 2;
                    deep--;
                    continue;
                }
            }
        }
        return dl;
    }
}
