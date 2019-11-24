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
            //lcc115(不同的子序列)
            vector<vector<int> > subsets(vector<int>& nums);
        private:
            vector<vector<int> > subsets(const vector<int>::iterator& begin,const vector<int>::iterator& end);
    };
    class section_8_1_3
    {
        public:
            //lcc46(全排列)
            vector<vector<int> > permute(vector<int> &num);
        private:
            vector<vector<int> > permute(const vector<int>::iterator& begin, const vector<int>::iterator& end);
    };
    class section_8_1_5
    {
        public:
            //lcc77(组合)
            vector<vector<int> > combine(int n, int k);
    };
}
#endif
