#include "ch6.h"

namespace p6
{
    int section6_6::firstMissingPositive(vector<int>& nums)
    {
        bucket_sort(nums);
        for (int i = 0; i < nums.size(); ++i)
            if(nums[i] != (i + 1))
                return i + 1;
        return nums.size() + 1;
    }
    void section6_6::bucket_sort(vector<int>& A)
    {
        const int n = A.size();
        for (int i = 0; i < n; i++)
        {
            while (A[i] != i + 1)
            {
                if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
                    break;
                swap(A[i], A[A[i] - 1]);
            }
        }
    }
}
