#include "ch8.h"
#include "math.h"

void test_section_8_1_1();
void test_section_8_1_3();
void test_section_8_1_5();

int main()
{
  test_section_8_1_5();
  return 0;
}
void test_section_8_1_1()
{
  p8::section_8_1_1* C = new p8::section_8_1_1();
  vector<int> nums{1, 2, 2};
  vector<vector<int> > res = C->subsets(nums);
  p8::print_matrix(res);
  cout << "[" << res.size() << "]" << endl;
  cout << "The number of subsets should be[2^" << nums.size() << "]: " << pow(2, nums.size()) << endl;
}
void test_section_8_1_3()
{
    vector<int> num{1, 1, 2};
    p8::section_8_1_3 *C = new p8::section_8_1_3();
    vector<vector<int> > result = C->permute(num);
    p8::print_matrix(result);
}
void test_section_8_1_5()
{
    int n = 5, k = 3;
    p8::section_8_1_5 *C = new p8::section_8_1_5();
    vector<vector<int> > result = C->combine(n, k);
    p8::print_matrix(result);
}
