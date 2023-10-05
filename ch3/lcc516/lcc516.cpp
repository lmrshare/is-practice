#include "ch3.h"
using namespace std;

//3.5 longest palindromic substring
void test_longest_palindromic_substring();
//lcc135, candy(hard)
int test_candy();

int main ()
{
  test_candy();
  return 0;
}

void test_longest_palindromic_substring()
{
    //TODO
    string s = "bbbab";
    int res = p3::longestPalindromeSubseq(s);
    std::cout << "The original string is: " << s << std::endl;
    std::cout << "The palindromic string is: " << res << std::endl;
    
}

int test_candy()
{
    //Doing
    vector<int> ratings = {1, 0, 2};
    int result = p3::candy(ratings);
    std::cout << "Output is: " << result << std::endl;
 
}