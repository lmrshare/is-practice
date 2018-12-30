#include "tree_structure.h"
#include <stack>
#include <queue>

namespace ts
{
    int lc687::longestUnivaluePath(TreeNode* root)
    {
        if(nullptr == root) return 0;
        if(nullptr != root && nullptr == root->left && nullptr == root->right) return 0;//leaf
        int len_l = longestUnivaluePath(root->left);
        int len_r = longestUnivaluePath(root->right);
        //pruning
        if(nullptr != root->left && root->val != root->left->val &&
           nullptr != root->right && root->val != root->right->val)
            return max(len_l, len_r);
        int r_left = pathFromNode(root->left, root->val);
        int r_right = pathFromNode(root->right, root->val);
        return max(max(len_l, len_r), r_left+r_right);
    }   

    int lc687::pathFromNode(TreeNode* root, int root_val)
    {
        int res = 0;
        if(nullptr != root && root->val == root_val)
        {
            res += 1;
            int left = 0;
            int right = 0;
            left += pathFromNode(root->left, root->val);
            right += pathFromNode(root->right, root->val);
            res += max(left, right);
        }
        //if(left > 0 && right > 0)
        //    return left + right;
        return res;
    }
    int lc852::peakIndexInMountainArray(vector<int>& A)
    {
#if 0//my solution
        size_t n = A.size();
        if(n < 3) return -1;
        int i = 0, j = n-1;
        int mid = (i+j)/2;
        while(i < j)
        {
            if(A[mid] > A[mid-1] && A[mid] > A[mid+1]) return mid;
            else if(A[mid] < A[mid-1])//right
                j = mid;
            else//left
                i = mid;
            mid = (i+j)/2;
        }
        return -1;
#elif 1
        int i,j;
        for (i=0,j=A.size()-1;i<j;){
            if (A[i+1]>A[i]) {
                i++;
            } else {
                return i;
            }
            if (A[j-1]>A[j]) {
                j --;
            } else {
                return j;
            }
        }
        return i;
#endif
    }
    vector<int> lcc94::inorderTraversal(TreeNode* root)
    {
      //1, 3, 2
      if(nullptr == root) return vector<int>(0, 0);
      vector<int> res(0, 0);
      stack<TreeNode*> q;
      TreeNode *p = root;//current point
      while(!q.empty() || p)
      {
        if(p)//to the left-down corner
        {
          q.push(p);
          p = p->left;
        }
        else
        {
          p = q.top();
          q.pop();
          res.push_back(p->val);
          p = p->right;//进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
        }
      }
      return res;
    }

    vector<int> lcc144::preorderTraversal(TreeNode* root)
    {
      if(nullptr == root) return vector<int>(0, 0);
      vector<int> res(0, 0);
      stack<TreeNode*> q;
      q.push(root);
      TreeNode *node = nullptr;
      while(!q.empty())
      {
        node = q.top();
        q.pop();
        res.push_back(node->val);
        if(node->right)
          q.push(node->right);
        if(node->left)
          q.push(node->left);
      }
      return res;
    }
    vector<int> lcc145::postorderTraversal(TreeNode* root)
    {
      if(nullptr == root) return vector<int>(0, 0);
      vector<int> res(0, 0);
      stack<TreeNode*> q;
      TreeNode *p = root;//current
      TreeNode *visited = nullptr;//p的子树的访问情况
      while(!q.empty() || p)
      {
        if(p)
        {
          q.push(p);
          p = p->left;
          continue;
        }
        p = q.top();
        if(nullptr == p->right || p->right == visited)//leaf or right visited
        {
          res.push_back(p->val);
          q.pop();
          visited = p;
          p = nullptr;//ensure the queue pop next element
        }
        else
          p = p->right;//进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
      }
      return res;
    }

    void print_vector(vector<int>& nums)
    {
      cout << "[";
      int i = 0;
      int size = nums.size()-1;
      for(auto & n : nums)
      {
        if(i++ < size)
          cout << n << ", ";
        else
          cout << n;
      }
      cout << "]" << endl;
    }
}
