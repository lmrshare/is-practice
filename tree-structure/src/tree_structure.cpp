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
    void print_matrix(vector<vector<int> >& nums)
    {
      for(auto v : nums)
        print_vector(v);
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
    int lcc104::maxDepth(TreeNode* root)
    {
        if(nullptr == root) return 0;
        queue<TreeNode*> e;e.push(root);
        queue<queue<TreeNode*> >q;q.push(e);
        int res = 1;
        while(!q.empty())
        {
            queue<TreeNode*> layer = q.front();
            q.pop();
            queue<TreeNode*> nl;
            while(!layer.empty())
            {
                TreeNode *node = layer.front();
                layer.pop();
                if(nullptr != node->left)
                    nl.push(node->left);
                if(nullptr != node->right)
                    nl.push(node->right);
            }
            if(nl.size() > 0)
            {
                q.push(nl);
                ++res;
            }
        }
        return res;
    }
    TreeNode* lcc105::buildTree(vector<int>& preorder, vector<int>& inorder)
    {
#if 0
        if(preorder.size() != inorder.size() || preorder.size() == 0) return nullptr;
        map<int, int> mpp, mpi;
        for(size_t i = 0; i < preorder.size();++i)
        {
            mpp[preorder[i]] = i;
            mpi[inorder[i]] = i;
        }
        TreeNode *root = nullptr;
        int s = 0, f = preorder.size() - 1;
        for(auto r : preorder)
        {
            TreeNode *node = new TreeNode(r);
            if(mpp[r] == 0) root = node;
            int llen = mpi[r] - s;
            int rlen = f - mpi[r];
            if(llen > 0)
                node->left = new TreeNode(preorder[mpp[r]+1]);
            if(rlen > 0)
                node->right = new TreeNode(preorder[mpp[r]+llen+1]);
        }

#elif 1
        if(preorder.size() != inorder.size() || preorder.size() == 0) return nullptr;
        map<int, int> mpp, mpi;
        for(size_t i = 0; i < preorder.size();++i)
        {
            mpp[preorder[i]] = i;
            mpi[inorder[i]] = i;
        }
        return buildTree(preorder.begin(),
                         preorder.end(),
                         inorder.begin(),
                         inorder.end(),
                         mpp,
                         mpi,
                         preorder,
                         inorder
                        );
#endif
    }
            TreeNode* lcc105::buildTree(vector<int>::iterator preb,
                                        vector<int>::iterator pref,
                                        vector<int>::iterator inb,
                                        vector<int>::iterator inf,
                                        map<int, int>& mpp,
                                        map<int, int>& mpi,
                                        vector<int>& preorder,
                                        vector<int>& inorder
                                        )
            {
                size_t num = pref - preb;
                if(0 == num) return nullptr;
                TreeNode *root = new TreeNode(*preb);
                if(1 == num) return root; 
                int llen = mpi[root->val] - (inb - inorder.begin());//index of root in inorder  -  
                int rlen = inf - inorder.begin()-1-mpi[root->val];
                if(llen > 0)
                {
                    TreeNode *lr = buildTree(preb+1, preb+llen+1, inb, inb+llen,mpp, mpi,preorder, inorder);
                    root->left = lr;
                }
                if(rlen > 0)
                {
                    TreeNode *rr = buildTree(preb+llen+1, pref, inb+llen+1, inf, mpp, mpi, preorder, inorder);
                    root->right = rr;
                }
                return root;
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
    bool lcc101::isSymmetric(TreeNode* root)
    {
#if 0
      //this answer is error
      if(nullptr == root) return true;
      stack<TreeNode*> q;
      TreeNode *p = root;
      vector<int> res;
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
          res.push_back(p->val);
          p = p->right;
        }
      }
      size_t num = res.size();
      if(0 == num % 2) return false;
      for(size_t i = 0; i < num; ++i)
      {
        if(res[i] != res[num-1-i])
          return false;
      }
      return true;
#elif 1
      if(nullptr == root) return true;
      queue<TreeNode*>q;
      q.push(root);
      q.push(root);
      while(!q.empty())
      {
        TreeNode *t1 = q.front();
        q.pop();
        TreeNode *t2 = q.front();
        q.pop();
        if(nullptr == t1 && nullptr == t2) continue;
        if(nullptr == t1 || nullptr == t2) return false;
        if(t1->val != t2->val) return false;
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
      }
      return true;
#endif
    }
    vector<vector<int> > lcc102::levelOrder(TreeNode* root)
    {
      vector<vector<int> > res(0, vector<int>(0, 0));
      if(nullptr == root)
        return res;
      queue<TreeNode*>e;e.push(root);
      queue<queue<TreeNode*> >q;
      q.push(e);
      TreeNode *node = nullptr;
      while(!q.empty())
      {
        queue<TreeNode*> layer = q.front();
        q.pop();
        vector<int> vl(0, 0);
        queue<TreeNode*> nl;
        while(!layer.empty())
        {
          node = layer.front();
          layer.pop();
          vl.push_back(node->val);
          if(node->left)
            nl.push(node->left);
          if(node->right)
            nl.push(node->right);
        }
        if(nl.size() > 0)
          q.push(nl);
        if(vl.size() > 0)
          res.push_back(vl);
      }
      return res;
    }
    vector<vector<int> > lcc103::zigzagLevelOrder(TreeNode* root)
    {
      vector<vector<int> >res(0, vector<int>(0, 0));
      if(nullptr == root) return res;
      queue<TreeNode*> e;e.push(root);
      queue<queue<TreeNode*> >q;
      q.push(e);
      bool flag = true;
      TreeNode *node = nullptr;
      while(!q.empty())
      {
        queue<TreeNode*> layer = q.front();
        q.pop();
        queue<TreeNode*> nl;
        vector<int> vl(0, 0);
        while(!layer.empty())
        {
          node = layer.front();
          layer.pop();
          if(flag)
            vl.push_back(node->val);
          else
            vl.insert(vl.begin(), node->val);
          if(node->left)
            nl.push(node->left);
          if(node->right)
            nl.push(node->right);
        }
        if(flag) flag = false;
        else flag = true;
        if(nl.size() > 0)
          q.push(nl);
        if(vl.size() > 0)
          res.push_back(vl);
      }
      return res;
    }
    vector<vector<int> > lcc107::levelOrderBottom(TreeNode* root)
    {
      vector<vector<int> > res(0, vector<int>(0, 0));
      if(nullptr == root) return res;
      queue<TreeNode*>e;e.push(root);
      queue<queue<TreeNode*> >q;q.push(e);
      queue<TreeNode*> layer;
      while(!q.empty())
      {
        layer = q.front();
        q.pop();
        queue<TreeNode*> nl;
        vector<int> val_l;
        while(!layer.empty())
        {
          TreeNode *node = layer.front();
          layer.pop();
          val_l.push_back(node->val);
          if(nullptr != node->left)
            nl.push(node->left);
          if(nullptr != node->right)
            nl.push(node->right);
        }
        if(val_l.size()!=0)
          res.insert(res.begin(), val_l);
        if(nl.size() != 0)
          q.push(nl);
      }
      return res;
    }
    TreeNode* lcc108::sortedArrayToBST(vector<int>& nums)
    {
      return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    TreeNode* lcc108::sortedArrayToBST(vector<int>& nums, int start, int finish)
    {
      if(finish < 0) return nullptr;
      if(start == finish) return new TreeNode(nums[start]);
      if(start + 1 == finish)
      {
        TreeNode *root = new TreeNode(nums[start]);
        root->right = new TreeNode(nums[finish]);
        return root;
      }
      //number of nums is at least 3.
      int mid = (start + finish)/2;
      TreeNode *root = new TreeNode(nums[mid]);
      TreeNode *left = sortedArrayToBST(nums, start, mid-1);
      TreeNode *right = sortedArrayToBST(nums, mid+1, finish);
      root->left = left;
      root->right = right;
      return root;
    }
    bool lcc110::isBalanced(TreeNode* root)
    {
      if(nullptr == root) return true;
      int lheight = 0, rheight = 0;
      bool l = false, r = false;
      l = isBalanced(root->left, lheight);
      r = isBalanced(root->right, rheight);
      if(l && r && abs(lheight-rheight) <= 1)
        return true;
      return false;
    }
    bool lcc110::isBalanced(TreeNode* root, int& depth)
    {
      if(nullptr == root)
      {
        depth = 0;
        return true;
      }
      if(nullptr == root->left && nullptr == root->right)
      {
        depth = 1;
        return true;
      }
      int lheight = 0, rheight = 0;
      bool l = false, r = false;
      l = isBalanced(root->left, lheight);
      r = isBalanced(root->right, rheight);
      depth = max(lheight, rheight) + 1;
      if(l && r && abs(lheight-rheight) <=1 )return true;
      return false;
    }
   }
