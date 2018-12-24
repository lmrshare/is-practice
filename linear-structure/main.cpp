#include "linear_structure.h"
#include <stack>

//Pointers
void testlc344();
void testlc763();
//LinkedList
void testlc876();
void testlc817();
void testlcc2();
//Queue, Deque

//Stack
void testlc682();
void testlc921();

int main()
{
    testlcc2();
    return 0;
}
void testlc344()
{
    ls::lc344 *C = new ls::lc344();
    string s("A man\na plan\ncanal: Panama");
    string res = C->reverseString1(s);
    cout << "Output:\n" << res << endl;
}
void testlc763()
{
    ls::lc763 *C = new ls::lc763();
    string S("ababcbacadefegdehijhklij");
    vector<int> result = C->partitionLabels(S);
    cout << endl;
    ls::printvector(result);
    cout << endl;
}
void testlc876()
{
    ls::lc876 *C = new ls::lc876();
    ls::ListNode *head = new ls::ListNode(1);
    ls::ListNode *node1 = new ls::ListNode(2);
    ls::ListNode *node2 = new ls::ListNode(3);
    ls::ListNode *node3 = new ls::ListNode(4);
    ls::ListNode *node4 = new ls::ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    ls::ListNode *middle = C->middleNode(head);
    ls::printListNode(middle);
}
void testlc817()
{
    ls::lc817 *C = new ls::lc817();
    ls::ListNode *head = new ls::ListNode(0);
    ls::ListNode *node1 = new ls::ListNode(1);
    ls::ListNode *node2 = new ls::ListNode(2);
    ls::ListNode *node3 = new ls::ListNode(3);
    //ls::ListNode *node4 = new ls::ListNode(4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    //node3->next = node4;
    //vector<int> G{0, 3, 1, 4};
    vector<int> G{0, 1, 3};
    //ls::printListNode(head);
    int num = C->numComponents(head, G);
    cout << "Output: " << num << endl;
}
void testlc682()
{
    ls::lc682 *C = new ls::lc682();
    vector<string> ops{"5","-2","4","C","D","9","+","+"};//{"5","2","C","D","+"};
    int res = C->calPoints(ops);
    cout << "The sum is: " << res << endl;
}
void testlc921()
{
    ls::lc921 *C = new ls::lc921();
    string S("()))((");
    int res = C->minAddToMakeValid(S);
    cout << "Output: " << res << endl;
}
void testlcc2()
{
    ls::lcc2 *C = new ls::lcc2();
#if 0
    ls::ListNode *l1 = new ls::ListNode(2);
    ls::ListNode *node1 = new ls::ListNode(4);
    ls::ListNode *node2 = new ls::ListNode(3);
    l1->next = node1;
    node1->next = node2;
    ls::ListNode *l2 = new ls::ListNode(5);
    ls::ListNode *node3 = new ls::ListNode(6);
    ls::ListNode *node4 = new ls::ListNode(4);
    l2->next = node3;
    node3->next = node4;
#elif 1
    ls::ListNode *l1 = new ls::ListNode(5);
    ls::ListNode *l2 = new ls::ListNode(5);
#endif
    ls::ListNode *res = C->addTwoNumbers(l1, l2);
}
