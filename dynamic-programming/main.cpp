#include "dynamic.h"

//easy
void test_lc121();
void test_lc53();
void test_lc198();
void test_lc338();
void test_lc647();
void test_lc120();
void test_lc474();
void test_lcc5();
void test_lccxxx();
void test_lcc53();
void test_lcc62();
void test_lcc63();
void test_lcc264();
void test_lcc279();
void test_lcc300();
void test_lcc303();
void test_lcc304();
void test_lcc309();
int main()
{
    test_lcc309();
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
void test_lc647()
{
    dp::lc647 *C = new dp::lc647();
    string s("aaa");
    int res = C->countSubstrings(s);
    cout << "Output: " << res << endl;
}
void test_lc120()
{
    vector<vector<int> > triangle{
                                {2},
                              {3, 4},
                             {6, 5, 7},
                            {4, 1, 8, 3}};
    dp::lc120 *C = new dp::lc120();
    int res = C->minimumTotal(triangle);
    cout << "Output: " << res << endl;
}
void test_lc474()
{
#if 0
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;
#elif 1
    vector<string> strs{"10", "0", "1"};
    int m = 1;
    int n = 1;
#endif
    dp::lc474 *C = new dp::lc474();
    int res = C->findMaxForm3(strs, m, n);
    cout << "Output: " << res << endl;
}
void test_lcc5()
{
    dp::lcc5 *C = new dp::lcc5();
#if 1
    string s("cbbd");
#elif 0
    string s("babad");
#endif
    string res = C->longestPalindrome3(s);
    cout << "Output: " << res << endl;
}
void test_lccxxx()
{
#if 0
    const char *s = "aa";
    const char *p = "a";
#elif 0
    const char *s = "aa";
    const char *p = "aa";
#elif 0
    const char *s = "aaa";
    const char *p = "aa";
#elif 0
    const char *s = "aa";
    const char *p = "a*";
#elif 0
    const char *s = "aa";
    const char *p = ".*";
#elif 0
    const char *s = "ab";
    const char *p = ".*";
#elif 1
    const char *s = "aab";
    const char *p = "c*a*b";
#endif
    dp::lccxxx *C = new dp::lccxxx();
    bool res = C->isMatch(s, p);
    cout << "Output:" << res << endl;
}
void test_lcc53()
{
    vector<int>nums{-2,1,-3,4,-1,2,1,-5,4};
    dp::lcc53 *C = new dp::lcc53();
    int res = C->maxSubArray(nums);
    cout << "Output: " << res << endl;
    delete C;
}
void test_lcc62()
{
  dp::lcc62 *C = new dp::lcc62();
  int m = 3;
  int n = 2;
  int res = C->uniquePaths(m, n);
  cout << "[62]Output: " << res << endl;
  delete C;
}
void test_lcc63()
{
  dp::lcc63 *C = new dp::lcc63();
#if 0
  vector<vector<int> >og{
                          {0,0,0},
                          {0,1,0},
                          {0,0,0} 
                        };
#elif 1
  vector<vector<int> >og{{0}};
#endif
  int num = C->uniquePathsWithObstacles(og);
  cout << "[63]Output: " << num << endl;
}
void test_lcc264()
{
    dp::lcc264 *C = new dp::lcc264();
    int val = C->nthUglyNumber(10);
    cout << "[264]Output: " << val << endl;
    delete C;
}
void test_lcc279()
{
    dp::lcc279 *C = new dp::lcc279();
    int res = C->numSquares(12);
    cout << "[279]Output: " << res << endl;
    delete C;
}
void test_lcc300()
{
    dp::lcc300 *C = new dp::lcc300;
#if 0
    vector<int> nums{10,9,2,5,3,7,101,18};
#elif 1
    vector<int> nums{-2, -1};
#endif
    int res = C->lengthOfLIS(nums);
    cout << "[300]Output: " << res << endl;
    delete C;
}
void test_lcc303()
{
    vector<int> nums{-2, 0, 3, -5, 2, -1};
    dp::NumArray *obj = new dp::NumArray(nums);
    int param = obj->sumRange(0, 5);
    cout << "[303]Output: " << param << endl;
}
void test_lcc304()
{
#if 0
    vector<vector<int> >nums{
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
#elif 1
    vector<vector<int> >nums{
        {-1},
        {0, 0, 0, 0}
    }; 
#endif
    dp::NumMatrix *obj = new dp::NumMatrix(nums);
#if 0
    int param = obj->sumRegion(2, 1, 4, 3);
#elif 0
    int param = obj->sumRegion(1, 1, 2, 2);
#elif 0
    int param = obj->sumRegion(1, 2, 2, 4);
#elif 1
    int param = obj->sumRegion(0, 0, 0, 0);
#endif
    cout << "[304]Output: " << param << endl;
}
void test_lcc309()
{
    dp::lcc309 *C = new dp::lcc309;
    vector<int> num{1,2,3,0,2};
    int price = C->maxProfit(num);
    cout << "[309]Output: " << price << endl;
    delete C;
}
