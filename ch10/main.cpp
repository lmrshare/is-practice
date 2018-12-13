#include "ch10.h"

void test_section10_1();
void test_section10_4();

int main()
{
  test_section10_4(); 
  return 0;
}
void test_section10_1()
{
    std::string s("aab");
    p10::section10_1 *C = new p10::section10_1();
    vector<vector<std::string> > res = C->partition(s);
    //p10::print2Dvector<std::string>(res);
    p10::print2Dvector(res);
}

void test_section10_4()
{
    p10::section10_4 *C = new p10::section10_4();
    int n = 5;
    vector<vector<std::string> > res = C->solveNQueens(n);
    p10::print2Dvector2(res);
}
