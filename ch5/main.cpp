#include "ch5.h"

void test_section5_1_1();
void test_section5_1_2();
void test_section5_1_3();
//skip
void test_section5_2_1();
//skip
void test_section5_3_1();

int main()
{
    test_section5_3_1();
    return 0;
}
void test_section5_1_1()
{
    p5::TreeNode *root = new struct p5::TreeNode(1);
    p5::TreeNode *node = new struct p5::TreeNode(2);
    //root->left = new struct p5::TreeNode(5);
    root->right = node;
    p5::TreeNode *node1 = new struct p5::TreeNode(3);
    node->left = node1;
    p5::section5_1_1 *C = new p5::section5_1_1();
    C->preorder_traversal_queue(root);
    delete C;
}
void test_section5_1_2()
{
    p5::TreeNode *root = new struct p5::TreeNode(1);
    p5::TreeNode *node = new struct p5::TreeNode(2);
    //root->left = new struct p5::TreeNode(5);
    root->right = node;
    p5::TreeNode *node1 = new struct p5::TreeNode(3);
    node->left = node1;
    p5::section5_1_2 *C = new p5::section5_1_2();
    C->preorfer_inorder_traversal_stack(root);
    delete C;
}
void test_section5_1_3()
{
    p5::TreeNode *root = new struct p5::TreeNode(1);
    p5::TreeNode *node = new struct p5::TreeNode(2);
    //root->left = new struct p5::TreeNode(5);
    root->right = node;
    p5::TreeNode *node1 = new struct p5::TreeNode(3);
    node->left = node1;
    p5::section5_1_3 *C = new p5::section5_1_3();
    C->postorder_inorder_traversal_stack(root);
    delete C;
}
void test_section5_2_1()
{
    int preints[] = {3,9,20,15,7};
    int inints[] = {9,3,15,20,7};
    size_t len = sizeof(preints)/sizeof(int);
    vector<int> preorder(preints, preints + len);
    vector<int> inorder(inints, inints + len);
    p5::section5_2_1 * C = new p5::section5_2_1();
    p5::TreeNode *root = C->build_tree(preorder, inorder);
    //test
    p5::section5_1_1 *C1 = new p5::section5_1_1();
    C1->preorder_traversal_queue(root);
}
void test_section5_3_1()
{
    int preints[] = {3,9,20,15,7};
    int inints[] = {9,3,15,20,7};
    size_t len = sizeof(preints)/sizeof(int);
    vector<int> preorder(preints, preints + len);
    vector<int> inorder(inints, inints + len);
    p5::section5_2_1 * C = new p5::section5_2_1();
    p5::TreeNode *root = C->build_tree(preorder, inorder);
    //test
    p5::section5_3_1 *C1 = new p5::section5_3_1();
    int num = C1->numTrees(3);
    cout << "num of trees: " << num << endl;
}

