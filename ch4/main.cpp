#include "ch4.h"
using namespace std;
//test largest rectangle area
void test_lra();
int main ()
{
  test_lra();
  return 0;
}

void test_lra()
{
  vector<int> height(0);
  height.push_back(2);
  height.push_back(1);
  height.push_back(5);
  height.push_back(6);
  height.push_back(2);
  height.push_back(3);
  int rst = p4::largest_rectangle_area(height);
  cout << "The result is: " << rst << endl;

}

