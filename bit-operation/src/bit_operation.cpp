#include "bit_operation.h"
#include <map>

namespace bo
{
    int lcc136::singleNumber(vector<int>& nums)
    {
        int res = 0;
        for(auto & n : nums)
            res ^= n;
        return res;
    }
    int lcc137::singleNumber(vector<int>& nums)
    {
        int res = 0;
        int bit;
        int num = 0;
        for(int i = 0; i < 32; ++i)
        {
            num = 0;
            bit = 1 << i;
            for(int n : nums)
            {
                if(n&bit)
                    ++num;
            }
            if(num % 3 == 1)
                res |= bit;
        }
        return res;
    }
    int lcc169::majorityElement(vector<int>& nums)
    {
        map<int, int>freq;
        for(int n : nums)
            freq[n]++;
        for(int n : nums)
            if(freq[n] > nums.size()/2) return n;
    }
    int lcc169::majorityElement2(vector<int>& nums)
    {
        quicksort(nums, 0, nums.size()-1);
        return nums[nums.size()/2];
    }
    void lcc169::quicksort(vector<int>& nums, int p, int r)
    {
        if(p == r) return;//one element
        if(p+1 == r)//two elements
        {
            if(nums[p] > nums[r])//exchange
            {
                int tmp = nums[p];
                nums[p] = nums[r];
                nums[r] = tmp;
            }
            return;
        }
        //at least 3 elements
#if 0
        int q = partion(nums, p, r);
        if(q == p)
            quicksort(nums, q+1, r);
        else
        {
            quicksort(nums, p, q-1);
            if(q < r)
                quicksort(nums, q+1, r);
        }
#elif 1
        while(p < r)
        {
            int q = partion(nums, p, r);
            if(q == p)
            {
                p++;
                continue;
            }
            quicksort(nums, p, q-1);
            p = q+1;
        }
#endif
    }
    int lcc169::partion(vector<int>& nums, int p, int r)
    {
        int x = nums[r];//主元
        int i = p-1;
        for(int j = p; j <= r-1;++j)
            if(nums[j] <= x)
            {
                i++;
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        i++;
        int tmp = nums[i];
        nums[i] = nums[r];
        nums[r] = tmp;
        return i;
    }
    void lcc169::quicksort(vector<int>& nums)
    {
        //TODO
    }
}
