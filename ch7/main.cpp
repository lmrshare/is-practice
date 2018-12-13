#include "ch7.h"

void test_section_7_1();
void test_section_7_2();
void test_section_7_3();

int main()
{
    test_section_7_3();
    return 0;
}
void test_section_7_1()
{
    int vals[] = {5, 7, 7, 8, 8, 10};
    size_t len = sizeof(vals)/sizeof(int);
    vector<int> nums(vals, vals+len);
    p7::section_7_1 *C = new p7::section_7_1();
    vector<int> res = C->searchRange(nums, 8);
}
void test_section_7_2()
{
    int vals[] = {1,3,5,6};
    int target = 7;//5;
    size_t len = sizeof(vals)/sizeof(int);
    vector<int> nums(vals, vals+len);
    p7::section_7_2 *C = new p7::section_7_2();
    int index = C->searchInsert(nums, target);
    cout << "The index is: " << index << endl;
}
void test_section_7_3()
{
#if 0
    int vals[3][4] = {
        1,   3,  5,  7,
        10, 11, 16, 20,
        23, 30, 34, 50};
    vector<vector<int> > nums2(3, vector<int>(4));
    for(size_t i = 0; i < 3; ++i)
        for(size_t j = 0; j < 4; ++j)
            nums2[i][j] = vals[i][j];
#endif
    //c++ 11
    vector<vector<int> > nums{
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}};
    int target = 11;
    p7::section_7_3 *C = new p7::section_7_3();
    bool res = C->searchMatrix(nums, target);
    if(res) cout << "Output is: true"  << endl;
    else cout << "Output is: false "  << endl;
}
