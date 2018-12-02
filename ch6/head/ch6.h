#ifndef CH6
#define CH6
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

namespace p6
{
    //skip residual of 6
    class section6_6
    {
    public:
        int firstMissingPositive(vector<int>& nums);
    private:
        void bucket_sort(vector<int>& A);
    };
}
#endif
