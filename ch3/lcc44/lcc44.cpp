#include "ch3.h"
using namespace std;

//Wildcard Matching
void test_wildcard_matching();

int main ()
{
  test_wildcard_matching();
  return 0;
}
void test_wildcard_matching()
{
    string s = "aa";
    string p = "a";
    bool res = p3::isMatch(s, p);
    cout << "res: " << boolalpha << res << endl;
}