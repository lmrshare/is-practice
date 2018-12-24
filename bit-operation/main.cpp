#include "bit_operation.h"
//exp[this part can be removed]
#include <functional>
#include <iostream>
#include <string>

void testlcc136();
void testlcc137();
void testlcc169();
int main()
{
    testlcc169();
    return 0;
}
void testlcc136()
{
#if 1
    vector<int>nums{2, 2, 2};
#elif 0
    vector<int>nums{4,1,2,1,2};
#endif
    bo::lcc136 *C = new bo::lcc136();
    int res = C->singleNumber(nums);
    cout << "Output: " << res << endl;
}
void testlcc137()
{
#if 0
    vector<int>nums{2,2,3,2};
#elif 1
    vector<int>nums{0,1,0,1,0,1,99};
#endif
    bo::lcc137 *C = new bo::lcc137();
    int res = C->singleNumber(nums);
    cout << "Output: " << res << endl;
}
void testlcc169()
{
#if 0
    vector<int>nums{2, 1, 2, 3, 2};
#elif 1
    vector<int>nums{2, 1, 2, 2};
#endif
    bo::lcc169 *C = new bo::lcc169();
    int res = C->majorityElement2(nums);
    cout << "Output: " << res << endl;
}
