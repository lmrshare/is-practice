#include "ch13.h"

void test_sectionn_n_n();
void test_section13_3();

int main()
{
  test_section13_3();
  return 0;
}
void test_sectionn_n_n()
{
  p13::sectionn_n_n* C = new p13::sectionn_n_n();
  vector<int> ints;
  C->demofunction(ints);
}
void test_section13_3()
{
    p13::section13_3 *C = new p13::section13_3();
    string s = "aab";
    int min_num = C->minCut(s);
    cout << "Min num is: " << min_num << endl;
}
