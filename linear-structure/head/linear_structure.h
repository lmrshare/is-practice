#ifndef LINEARSTRUCTURE
#define LINEARSTRUCTURE
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
#include <map>
using namespace std;

namespace ls
{
    struct ListNode;
    //tool functions
    void printvector(const vector<int>& res);
    void printListNode(ListNode* res);
    //Pointers
    class lc344//Reverse String
    {
        public:
            string reverseString(string s);//index version
            string reverseString1(string s);//pointer version
            string reverseString2(string s);//with the help of STL(from Discuss)
            char* reverseString(char* s);//c version(from Discuss)
    };
    class lc763//Partition Labels
    {
        public:
            vector<int> partitionLabels(string S);
    };
    //LinkedList
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    class lc876//Middle of the Linked List
    {
        public:
            ListNode* middleNode(ListNode* head);
    };
    class lc817//Linked List Components, 这道题不对
    {
        public:
            int numComponents(ListNode* head, vector<int>& G);
        private:
            //std::hash<std::vector<int> > link_component;
            std::map<std::vector<int>, bool> link_component;
    };
    //Queue, Deque
    //Stack
    class lc682// Baseball Game
    {
        public:
            int calPoints(vector<string>& ops);
    };
    class lc921//Minimum Add to Make Parentheses Valid(stack, Greedy)
    {
        public:
            int minAddToMakeValid(string S);
    };
    
}
#endif
