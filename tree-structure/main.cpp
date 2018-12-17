#include "tree_structure.h"



//Recursion
void testlc687();
//Binary search and Sorting
void testlc852();
//Binary tree
//Binary Search tree

int main()
{
    testlc852();
}
void testlc687()
{
    ts::lc687 *C = new ts::lc687();
#if 1
    ts::TreeNode *root = new ts::TreeNode(4);
    ts::TreeNode *node1 = new ts::TreeNode(-7);
    ts::TreeNode *node2 = new ts::TreeNode(-3);
    root->left = node1;
    root->right = node2;
    ts::TreeNode *node3 = new ts::TreeNode(-9);
    ts::TreeNode *node4 = new ts::TreeNode(-3);
    node2->left = node3;
    node2->right = node4;
    ts::TreeNode *node5 = new ts::TreeNode(9);
    ts::TreeNode *node6 = new ts::TreeNode(-7);
    node3->left = node5;
    node3->right = node6;
    ts::TreeNode *node7 = new ts::TreeNode(-4);
    node4->left = node7;
    ts::TreeNode *node8 = new ts::TreeNode(6);
    node5->left = node8;
    ts::TreeNode *node9 = new ts::TreeNode(-6);
    ts::TreeNode *node10 = new ts::TreeNode(-6);
    node6->left = node9;
    node6->right = node10;
    ts::TreeNode *node11 = new ts::TreeNode(0);
    ts::TreeNode *node12 = new ts::TreeNode(6);
    node8->left = node11;
    node8->right = node12;
    ts::TreeNode *node13 = new ts::TreeNode(5);
    ts::TreeNode *node14 = new ts::TreeNode(0);
    node9->left = node13;
    node10->left = node14;
    ts::TreeNode *node15 = new ts::TreeNode(-1);
    node11->right = node15;
    ts::TreeNode *node16 = new ts::TreeNode(-4);
    node12->left = node16;
    ts::TreeNode *node17 = new ts::TreeNode(-2);
    node14->left = node17;
#elif 0
    ts::TreeNode *root = new ts::TreeNode(5);
    ts::TreeNode *node1 = new ts::TreeNode(4);
    ts::TreeNode *node2 = new ts::TreeNode(5);
    root->left = node1;
    root->right = node2;
    ts::TreeNode *node3 = new ts::TreeNode(1);
    ts::TreeNode *node4 = new ts::TreeNode(1);
    node1->left = node3;
    node1->right = node4;
    ts::TreeNode *node5 = new ts::TreeNode(5);
    node2->right = node5;
#elif 0
    ts::TreeNode *root = new ts::TreeNode(1);
    ts::TreeNode *node1 = new ts::TreeNode(4);
    ts::TreeNode *node2 = new ts::TreeNode(5);
    root->left = node1;
    root->right = node2;
    ts::TreeNode *node3 = new ts::TreeNode(4);
    ts::TreeNode *node4 = new ts::TreeNode(4);
    node1->left = node3;
    node1->right = node4;
    ts::TreeNode *node5 = new ts::TreeNode(5);
    node2->right = node5;
#endif
    int res = C->longestUnivaluePath(root);
    cout <<"Output: " << res << endl;
}
void testlc852()
{
    ts::lc852 *C = new ts::lc852();
    vector<int> A{0,2,1,0};
    int res = C->peakIndexInMountainArray(A);
    cout << "Ouput: " << res << endl;
}
