#include "graph_search.h"

//Depth First Search
void testlc559();
//Breadth Fitst Search
void testlc513();
void testlcc133();//和testclonetree原理一样
void testclonetree();
void testlcc329();
//Dijkstra's algorithm(Best First Search)
//Union Find

int main()
{
  testlcc329();
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
void testlcc133()
{
    gs::UndirectedGraphNode *node = new gs::UndirectedGraphNode(0);
    gs::UndirectedGraphNode *node1 = new gs::UndirectedGraphNode(1);
    gs::UndirectedGraphNode *node2 = new gs::UndirectedGraphNode(2);
    //0
    node->neighbors.push_back(node1);
    node->neighbors.push_back(node2);
    //1
    node1->neighbors.push_back(node2);
    //2
    node2->neighbors.push_back(node2);
    gs::lcc133 *C = new gs::lcc133();
    gs::UndirectedGraphNode* res = C->cloneGraph(node);
}
void testclonetree()
{
    gs::TreeNode *root = new gs::TreeNode(0);
    gs::TreeNode *node1 = new gs::TreeNode(1);
    gs::TreeNode *node2 = new gs::TreeNode(2);
    root->left = node1;
    root->right = node2;
    gs::TreeNode *node3 = new gs::TreeNode(3);
    gs::TreeNode *node4 = new gs::TreeNode(4);
    node1->left = node3;
    node1->right = node4;
    gs::TreeNode *node5 = new gs::TreeNode(5);
    gs::TreeNode *node6 = new gs::TreeNode(6);
    node2->left = node5;
    node2->right = node6;
    gs::clonetree *C = new gs::clonetree();
    gs::TreeNode *res = C->cloneTree(root);
}
void testlcc329()
{
    vector<vector<int> > matrix{
                                {9,9,4},
                                {6,6,8},
                                {2,1,1}};
    gs::lcc329 *C = new gs::lcc329();
    int res = C->longestIncreasingPath(matrix);
    cout << "Output: " << res << endl;
}
