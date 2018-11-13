#include "ch5.h"

void test_section5_1_1();

int main()
{
    test_section5_1_1();
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
