#include "dynamic.h"

//easy
void test_lc121();
void test_lc53();
void test_lc198();
void test_lc338();
int main()
{
    test_lc338();
    return 0;
}
void test_lc121()
{
    dp::lc121 *C = new dp::lc121();
    vector<int> prices{7,6,4,3,1};//{7,1,5,3,6,4};
    int profit = C->maxProfit(prices);
    cout << "The max profit is: " << profit << endl;
}
void test_lc53()
{
    dp::lc53 *C= new dp::lc53();
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int max_sum = C->maxSubArray(nums);
    cout << "The Maximum Subarray: " << max_sum << endl;
}
void test_lc198()
{
    dp::lc198 *C = new dp::lc198();
    vector<int> nums{2,7,9,3,1};//{1,2,3,1};
    int money = C->rob(nums);
    cout << "Robbed money: " << money << endl;
}
void test_lc338()
{
    dp::lc338 *C = new dp::lc338();
    int num = 5;
    vector<int> res = C->countBits(num);
    dp::print_vector(res);
}
