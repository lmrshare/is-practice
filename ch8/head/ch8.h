#ifndef CH8
#define CH8
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace p8
{
    void print_matrix(const vector<vector<int> >& M);
    class section_8_1_1
    {
        public:
            vector<vector<int> > subsets(vector<int>& nums);
        private:
            vector<vector<int> > subsets(const vector<int>::iterator& begin,const vector<int>::iterator& end);
    };
    class section_8_1_3
    {
        public:
            vector<vector<int> > permute(vector<int> &num);
        private:
            vector<vector<int> > permute(const vector<int>::iterator& begin, const vector<int>::iterator& end);
    };
    class section_8_1_5
    {
        public:
            vector<vector<int> > combine(int n, int k);
    };
}
#endif
