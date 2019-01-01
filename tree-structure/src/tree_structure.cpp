#include "tree_structure.h"
#include <stack>
#include <queue>
#include <deque>

namespace ts
{
    //tool functions
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
    void print_tree(TreeNode *root)
    {
      cout << "print the tree: " << root->val << endl;
    }
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

    vector<int> left_view::lv(TreeNode *root)
    {
      if(nullptr == root) return vector<int>(0, 0);
      vector<int> res(0, 0);
      queue<TreeNode*>e;e.push(root);
      queue<queue<TreeNode*> >q;
      q.push(e);
      while(!q.empty())
      {
        queue<TreeNode*> layer = q.front();
        q.pop();
        //first element
        TreeNode *node = layer.front();
        res.push_back(node->val);
        queue<TreeNode*> n_layer;
        while(!layer.empty())
        {
          TreeNode *node = layer.front();
          layer.pop();
          if(node->left)
            n_layer.push(node->left);
          if(node->right)
            n_layer.push(node->right);
        }
        if(!n_layer.empty())
          q.push(n_layer);
      }
      return res;
    }
    vector<int> right_view::rv(TreeNode *root)
    {
      if(nullptr == root) return vector<int>(0, 0);
      vector<int> res(0, 0);
      queue<TreeNode*>e;e.push(root);
      queue<queue<TreeNode*> >q;
      q.push(e);
      while(!q.empty())
      {
        queue<TreeNode*> layer = q.front();
        q.pop();
        queue<TreeNode*> n_layer;
        while(!layer.empty())
        {
          TreeNode *node = layer.front();
          if(layer.size() == 1)
            res.push_back(node->val);
          layer.pop();
          if(node->left)
            n_layer.push(node->left);
          if(node->right)
            n_layer.push(node->right);
        }
        if(!n_layer.empty())
          q.push(n_layer);
      }
      return res;
    }       
    vector<int> all_leaf::al(TreeNode *root)
    {
      if(nullptr == root) return vector<int>(0, 0);
      vector<int> res(0, 0);
      queue<TreeNode*> q;
      q.push(root);
        TreeNode *node;
      while(!q.empty())
      {
        node = q.front();
        q.pop();
        bool leaf = false;
        if(node->left)
          q.push(node->left);
        else
          leaf = true;
        if(node->right)
        {
          q.push(node->right);
          leaf = false;
        }
        if(leaf)
          res.push_back(node->val);

      }
      return res;
    }
    vector<TreeNode*> lcc95::generateTrees(int n)
    {
      if(n <= 0) return vector<TreeNode*>(0, nullptr);
      vector<TreeNode*> res(0, nullptr);
      for(int i=1; i<=n; ++i)
      {
        int num = res.size();
        if(0 == num)
        {
          res.push_back(new TreeNode(i));
          continue;
        }
        for(int j = 0; j < num; ++j)
        {
          TreeNode *tree = res[j];
          stack<TreeNode*> r;//store all right son
          TreeNode *p = tree;
          while(p)//all right son
          {
            r.push(p);
            p = p->right;
          }
          int num_copy = r.size();
          vector<TreeNode*> trees(0, nullptr);
          gen_trees(tree, num_copy, trees);
          TreeNode *node = r.top();
          node->right = new TreeNode(i);//original tree
          int k = 0;
          while(!r.empty())//update all new tree
          {
            r.pop();
            TreeNode *tree_new = trees[k++];
            if(0 == r.size())//it is root
            {
              TreeNode *node1 = new TreeNode(i);
              node1->left = tree_new;
              trees[k-1] = node1;
            }
            else
            {
              p = tree_new;
              while(p->val != r.top()->val)
                p = p->right;
              TreeNode *oldr = p->right;
              p->right = new TreeNode(i);
              p->right->left = oldr;
            }
          }
          //add new tree
          for(auto nt : trees)
            res.push_back(nt);
        }
      }
      return res;
    }
    void lcc95::gen_trees(TreeNode *root, int num, vector<TreeNode*>& trees)
    {
      while(num-- > 0)
      {
        TreeNode *newroot = new TreeNode(root->val);
        queue<TreeNode*> q, q2;
        q.push(root);
        q2.push(newroot);
        TreeNode *p = nullptr;
        TreeNode *p2 = nullptr;
        while(!q.empty())
        {
          p = q.front();
          q.pop();
          p2 = q2.front();
          q2.pop();
          if(p->left)
          {
            q.push(p->left);
            p2->left = new TreeNode(p->left->val);
            q2.push(p2->left);
          }
          if(p->right)
          {
            q.push(p->right);
            p2->right = new TreeNode(p->right->val);
            q2.push(p2->right);
          }
        }
        trees.push_back(newroot);
      }
    }
    int lcc96::numTrees(int n)
    {
      if(n <= 0) return 0;
      if(n == 1) return 1;
      vector<int> dp(n+1, 0);
      dp[0] = 1;
      dp[1] = 1;
      for(int i = 2; i <= n; ++i)
      {
        for(int j = i-1; j>=0; --j)
          dp[i] += dp[j] * dp[i-1-j]; 
      }
      return dp[n];
    }
    bool lcc98::isValidBST(TreeNode* root)
    {
        if(nullptr == root) return true;
        int VAL = INFINITY;
        int maxV = -VAL;

        stack<TreeNode*> q;
        TreeNode *p = root;
        TreeNode *visited = nullptr;
        while(!q.empty() || p)
        {
            if(p)
            {
                q.push(p);
                p = p->left;
                continue;
            }
            p = q.top();
            if(nullptr == p->right || visited == p->right)
            {
                if(-VAL == maxV)
                    maxV = p->val;
#if 0
                else if(visited != p->right || nullptr == p->left && nullptr == p->right)
                {
                  //第一个条件代表只有一颗左子树
                 //第二个条件代表叶子节点
                 //不考虑(nullptr != visited  && visited == p->right)的情况, 因为这个case表明右子树已经访问完了, 这里不应该和p(即根)的值做判断(已经判断了)
#elif 1
                //这个判断条件实际上就是: !(nullptr != visited  && visited == p->right)
                else if(nullptr == visited || visited != p->right)
                {
#endif
                    if(p->val > maxV) maxV = p->val;
                    else return false;
                }
                q.pop();
                visited = p;
                p = nullptr;
            }
            else
            {
                if(-VAL == maxV)
                    maxV = p->val;
                else
                {
                    if(p->val > maxV) maxV = p->val;
                    else return false;
                }
                p = p->right;
            }
        }
        return true;
    }
    bool lcc98::isValidBST2(TreeNode* root)
    {
        if(nullptr == root) return true;
        int VAL = INFINITY;
        int maxV = -VAL;

        stack<TreeNode*> q;
        TreeNode *p = root;
        while(!q.empty() || p)
        {
            if(p)
            {
                q.push(p);
                p = p->left;
            }
            else
            {
                p = q.top();
                q.pop();
                if(-VAL == maxV)
                    maxV = p->val;
                else
                {
                    if(p->val > maxV) maxV = p->val;
                    else return false;
                }
                p = p->right;
            }
        }
        return true;
    }
    void lcc99::recoverTree(TreeNode* root)
    {
      if(nullptr == root) return;
      stack<TreeNode*> q;
      TreeNode *p = root;
      TreeNode *pre = nullptr;
      TreeNode *a = nullptr;
      TreeNode *b = nullptr;
      while(!q.empty() || p)
      {
        if(p)
        {
          q.push(p);
          p = p->left;
        }
        else
        {
          p = q.top();
          q.pop();
          if(pre && pre->val > p->val)
          {
            if(!a) a = pre;
            b = p;
          }
          pre = p;
          p = p->right;
        }
      }
      if(a && b)
        swap(a->val, b->val);
    }
}
