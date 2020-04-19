#include "april_algo.h"
using namespace std;

void test_lengthOfLongestSubstring();
//暂时未分类
void test_leastKMakeA_B_cntA_cntB();

int main ()
{
  test_leastKMakeA_B_cntA_cntB();
  return 0;
}

void test_lengthOfLongestSubstring()
{
    string str = "2147483646";
    int value = april_algo::lengthOfLongestSubstring(str);
    cout << "value: " << value << endl;
}

void test_leastKMakeA_B_cntA_cntB()
{
  int a, b, cnta, cntb;
  cin >> a >> b >> cnta >> cntb;
  int k = april_algo::leastKMakeA_B_cntA_cntB(a, b, cnta, cntb);
  cout << "k: " << k << endl;
}