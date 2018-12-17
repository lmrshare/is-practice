#include "graph_search.h"

//Depth First Search
void testlc559();
//Breadth Fitst Search
void testlc513();
//Dijkstra's algorithm(Best First Search)
//Union Find

int main()
{
  testlc513();
  return 0;
}
void testlc559()
{
    gs::lc559 *C = new gs::lc559();
    vector<gs::Node*> childs{
        new gs::Node(5, vector<gs::Node*>(0)),
        new gs::Node(6, vector<gs::Node*>(0))
    };
    vector<gs::Node*> children{
        new gs::Node(3, childs),
        new gs::Node(2, vector<gs::Node*>(0)),
        new gs::Node(4, vector<gs::Node*>(0))
    };
    gs::Node *root = new gs::Node(1, children);
    int res = C->maxDepth2(root);
    cout << "Output: " << res << endl;
}
void testlc513()
{
#if 0
    gs::TreeNode *root = new gs::TreeNode(2);
    gs::TreeNode *node1 = new gs::TreeNode(1);
    gs::TreeNode *node2 = new gs::TreeNode(3);
    root->left = node1;
    root->right = node2;
#elif 0
    gs::TreeNode *root = new gs::TreeNode(1);
    gs::TreeNode *node1 = new gs::TreeNode(2);
    gs::TreeNode *node2 = new gs::TreeNode(3);
    root->left = node1;
    root->right = node2;
    gs::TreeNode *node3 = new gs::TreeNode(4);
    node1->left = node3;
    gs::TreeNode *node4 = new gs::TreeNode(5);
    gs::TreeNode *node5 = new gs::TreeNode(6);
    node2->left = node4;
    node2->right = node5;
    gs::TreeNode *node6 = new gs::TreeNode(7);
    node4->left = node6;
#elif 0
    gs::TreeNode *root = new gs::TreeNode(0);
#elif 0
    gs::TreeNode *root = new gs::TreeNode(0);
    gs::TreeNode *node1 = new gs::TreeNode(-1);
    root->right = node1;
#elif 1
    gs::TreeNode *root = new gs::TreeNode(3);
    gs::TreeNode *node1 = new gs::TreeNode(1);
    gs::TreeNode *node2 = new gs::TreeNode(5);
    root->left = node1;
    root->right = node2;
    gs::TreeNode *node3 = new gs::TreeNode(0);
    gs::TreeNode *node4 = new gs::TreeNode(2);
    node1->left = node3;
    node1->right = node4;
    gs::TreeNode *node5 = new gs::TreeNode(4);
    gs::TreeNode *node6 = new gs::TreeNode(6);
    node2->left = node5;
    node2->right = node6;

#endif
    gs::lc513 *C = new gs::lc513();
    int res = C->findBottomLeftValue(root);
    cout << "Output: " << res << endl;
}
