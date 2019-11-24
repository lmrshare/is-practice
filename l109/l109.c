#include <stdio.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* sortedListToBST(struct ListNode* head);
struct TreeNode* sortedListToBST_helper(struct ListNode* head, int left, int right, int middle);

int main()
{
    //-10, -3, 0, 5, 9
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *nd1 = (struct ListNobde*)malloc(sizeof(struct ListNode));
    struct ListNode *nd2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *nd3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *nd4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = -10;
    nd1->val = -3;
    nd2->val = 0;
    nd3->val = 5;
    nd4->val = 9;
    head->next = nd1;
    nd1->next = nd2;
    nd2->next = nd3;
    nd3->next = nd4;
    nd4->next = NULL;
    struct TreeNode *root = sortedListToBST(head);
    return 0;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL)
        return NULL;
    int left = 0;
    int right = 0;
    struct ListNode *ptr = head;
    while(ptr != NULL)
    {
        right++;
        ptr = ptr->next;
    }
    int middle = right/2;
    return sortedListToBST_helper(head, 0, right-1, middle);
}
struct TreeNode* sortedListToBST_helper(struct ListNode* head, int left, int right, int middle) {
    struct ListNode *ptr = head;
    if(middle < left || left > right)
        return NULL;
    if(left == right)
    {
        for(int i = 0; i < left; ++i)
            ptr = ptr->next;
        struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = ptr->val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    for(int i = 0; i < middle; ++i)
        ptr = ptr->next;
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = ptr->val;
    root->left = sortedListToBST_helper(head, left, middle-1, (middle-left)/2 + left);
    root->right = sortedListToBST_helper(head, middle+1, right, (right-middle)/2 + middle+1);
    return root;
}
