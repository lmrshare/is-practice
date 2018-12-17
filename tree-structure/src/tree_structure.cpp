#include "tree_structure.h"

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
}
