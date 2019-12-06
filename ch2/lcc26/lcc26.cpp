#include "ch2.h"
using namespace p2;

void test_lcc26();

int main()
{
  test_lcc26();
  return 0;
}
void test_lcc26()
{
  cout<<"test_lcc26\n";
  vector<int> nums(0);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  int N = p2::removeDuplicates_lcc26(nums);
  cout << "res: " << N << endl;
}