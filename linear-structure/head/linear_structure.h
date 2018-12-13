#ifndef LINEARSTRUCTURE
#define LINEARSTRUCTURE
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace ls
{
    //tool functions
    void printvector(const vector<int>& res);
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
    //Queue, Deque
    //Stack
}
#endif
