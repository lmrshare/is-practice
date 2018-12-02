#include "ch6.h"

void test_section6_6();

int main()
{
  test_section6_6();
  return 0;
}
void test_section6_6()
{
    int vals[] = {3,4,-1,1};
    size_t len = sizeof(vals)/sizeof(int);
    vector<int> nums(vals, vals + len);
    p6::section6_6 * C = new p6::section6_6();
    int positive = C->firstMissingPositive(nums);
    cout << "The positive is: " << positive << endl;
}
