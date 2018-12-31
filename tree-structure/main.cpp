#include "tree_structure.h"



//Recursion
void testlc687();
//Binary search and Sorting
void testlc852();
//Binary tree
void testlcc94_lcc144_lcc145();
void test_right_view();
void test_lcc95();
void test_lcc96();
//Binary Search tree

int main()
{
    test_lcc96();
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
void testlcc94_lcc144_lcc145()
{
#if 0
    ts::TreeNode *root = new ts::TreeNode(1);
    ts::TreeNode *node1 = new ts::TreeNode(2);
    ts::TreeNode *node2 = new ts::TreeNode(3);
    root->right = node1;
    node1->left = node2;
#elif 0
    ts::TreeNode *root = new ts::TreeNode(3);
    ts::TreeNode *node1 = new ts::TreeNode(1);
    ts::TreeNode *node2 = new ts::TreeNode(2);
    root->left = node1;
    node1->right = node2;
#elif 1
    ts::TreeNode *root = new ts::TreeNode(4);
    ts::TreeNode *node1 = new ts::TreeNode(2);
    ts::TreeNode *node2 = new ts::TreeNode(7);
    root->left = node1;
    root->right = node2;
    ts::TreeNode *node3 = new ts::TreeNode(1);
    ts::TreeNode *node4 = new ts::TreeNode(3);
    node1->left = node3;
    node1->right = node4;
    ts::TreeNode *node5 = new ts::TreeNode(5);
    ts::TreeNode *node6 = new ts::TreeNode(8);
    node2->left = node5;
    node2->right = node6;
#endif
    ts::lcc94 *C = new ts::lcc94;
    vector<int> res = C->inorderTraversal(root);
    cout << "[94.in]Output" << endl;
    ts::print_vector(res);
    delete C;
    ts::lcc144 *C1 = new ts::lcc144;
    res = C1->preorderTraversal(root);
    cout << "[144.pre]Output" << endl;
    ts::print_vector(res);
    delete C1;
    ts::lcc145 *C2 = new ts::lcc145;
    res = C2->postorderTraversal(root);
    cout << "[145.post]Output" << endl;
    ts::print_vector(res);
    delete C2;

}
void test_right_view()
{
#if 0
    ts::TreeNode *root = new ts::TreeNode(1);
    ts::TreeNode *node1 = new ts::TreeNode(2);
    ts::TreeNode *node2 = new ts::TreeNode(3);
    root->right = node1;
    node1->left = node2;
#elif 1
    ts::TreeNode *root = new ts::TreeNode(3);
    ts::TreeNode *node1 = new ts::TreeNode(1);
    ts::TreeNode *node2 = new ts::TreeNode(2);
    root->left = node1;
    node1->right = node2;
#elif 0
    ts::TreeNode *root = new ts::TreeNode(4);
    ts::TreeNode *node1 = new ts::TreeNode(2);
    ts::TreeNode *node2 = new ts::TreeNode(7);
    root->left = node1;
    root->right = node2;
    ts::TreeNode *node3 = new ts::TreeNode(1);
    ts::TreeNode *node4 = new ts::TreeNode(3);
    node1->left = node3;
    node1->right = node4;
    ts::TreeNode *node5 = new ts::TreeNode(5);
    ts::TreeNode *node6 = new ts::TreeNode(8);
    node2->left = node5;
    node2->right = node6;
    ts::TreeNode *node7 = new ts::TreeNode(6);
    node5->right = node7;
#endif
    ts::left_view *C = new ts::left_view;
    vector<int> res = C->lv(root);
    cout << "[left view] Output:" << endl;
    ts::print_vector(res);
    delete C;
    ts::right_view *C1 = new ts::right_view;
    res = C1->rv(root);
    cout << "[right view] Output:" << endl;
    ts::print_vector(res);
    delete C1;
    ts::all_leaf *C2 = new ts::all_leaf;
    res = C2->al(root);
    cout << "[all leaf] Output:" << endl;
    ts::print_vector(res);
    delete C2;
}
void test_lcc95()
{
  ts::lcc95 *C = new ts::lcc95;
  int n = 3;
  vector<ts::TreeNode*> res = C->generateTrees(n);
  cout <<"[95] Output:" << endl;
  for(auto tree : res)
    ts::print_tree(tree);
  delete C;
}
void test_lcc96()
{
  ts::lcc96 *C = new ts::lcc96;
  int n;
  cout <<"Input n:" << endl;
  cin >> n;
  while(n > 0)
  {
    int res = C->numTrees(n);
    cout <<"[96] Output:" << res << endl;
    cout <<"Input n:" << endl;
    cin >> n;
  }
  delete C;
}
