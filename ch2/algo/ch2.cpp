#include "ch2.h"
#include <climits>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <assert.h>

namespace p2
{
    template<typename InIt,typename OutIt>
    OutIt section2_1_1::removeDuplicates(InIt first, InIt last, OutIt output)
    {
      while (first != last)
      {
        *output++ = *first;//1. *output = *first; 2. output++
        first = upper_bound(first, last, *first);
      }
        return output;
    }
    
    int section2_1_1::removeDuplicates(vector<int>& nums)
    {
     if (nums.empty())
        return 0;
      int index = 0;
      for (int i = 1; i < nums.size(); i++)
      {
       if (nums[index] != nums[i])
          nums[++index] = nums[i];
      }
      return index + 1;
    }
    int section2_1_1::removeDuplicates2(vector<int>& nums)
    {
      return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
    int section2_1_1::removeDuplicates3(vector<int>& nums)
    {
      return distance(nums.begin(), removeDuplicates(nums.begin(), nums.end(), nums.begin()    )  );
    }
    int section2_1_2::removeDuplicates(vector<int>& nums)
    {
      size_t N = nums.size();
      if(N <= 2)
        return N;
      int dnums = 1;
      int index = 0;
      for(size_t i = 1; i < N; ++i)
      {
         if(nums[index] == nums[i])
            ++dnums;
         else
            dnums = 1;
         if(dnums <= 2)
           nums[++index] = nums[i];
      }
      return index + 1;
    }
    int section2_1_2::removeDuplicates2(vector<int>& nums)
    {
      int n = nums.size();
      if(n <= 2)
        return n;
      int index = 0;
      for(size_t i = 0; i < n; ++i)
      {
        //Filter 3 duplicates
        if(i > 0 && i < n-1 && nums[i-1] == nums[i] && nums[i] == nums[i+1])
          continue;
        nums[index++] = nums[i];
      }
      return index;
    }
    int section2_1_2::removeDuplicates3(vector<int>& nums)
    {
      int n = nums.size();
      if(n <= 2)
        return n;
      int index = 0;
      for(size_t i = 0; i < n; ++i)
      {
        //Filter 3 duplicates
        if(i < n-2 && nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
          continue;
        nums[index++] = nums[i];
      }
      return index;
    }
    int Bonums_dpn::removeDuplicates(vector<int>& nums, int M)
    {
      int N = nums.size();
      if(N <= M)
        return N;
      int dnums = 1;
      int index = 0;
      for(size_t i = 1; i < N; ++i)
      {
        if(nums[index] == nums[i])
          ++dnums;
        else
          dnums = 1;
        if(dnums <= M)
          nums[++index] = nums[i];
      }
      return index + 1;
    }
    int Bonums_dpn::removeDuplicates3(vector<int>& nums, int M)
    {
      if(nums.size() < M)
        return nums.size();
      int index = M;//index point to the next position
      for(size_t i = M; i < nums.size(); ++i)
      {
        if(nums[i] != nums[index - M])
          nums[index++] = nums[i];
      }
      return index;
    }
    template<typename InIt, typename OutIt>
    OutIt Bonums_dpn::removeDuplicates(InIt first, InIt last, OutIt output, int M)
    {
    #if 0
      int dnums = 1;
      first++;
      while(first != last)
      {
        if(*output == *first)
          ++dnums;
        else
          dnums = 1;
        *++output = *first;
        if(dnums <= M)
            first = lower_bound(first,last,*first);
        else
            first = upper_bound(first,last,*first);
      }
    #endif
      return output;
    }
    int Bonums_dpn::removeDuplicates2(vector<int>& nums, int M)
    {
    #if 0
      vector<int>::iterator ite;
      ite = removeDuplicates(nums.begin(),nums.end(),nums.begin());
      return ite - nums.begin() + 1;
    #endif
      return distance(nums.begin(),removeDuplicates(nums.begin(),nums.end(),nums.begin(),M));
    }
    bool MDuplicate(const size_t& i,const vector<int>& nums, const int& M)
    {
      bool flag = true;
      for(int j = 1; j <= M;++j)
      {
        flag &= (nums[i] == nums[i+j]);
        if(!flag)
          break;
      }
      return flag;
    }
    int Bonums_dpn::removeDuplicates4(vector<int>& nums, int M)
    {
      int N = nums.size();
      if(N <= M)
        return N;
      int index = 0;
      for(size_t i = 0; i < N; ++i)
      {
        if(i < N-M && MDuplicate(i,nums,M))
          continue;
        nums[index++] = nums[i];
      }
      return index;
    }
    int section2_1_3::search(const vector<int>& nums, int target)
    {
      int first = 0;
      int last = nums.size() - 1;
      while(first != last)
      {
        const int mid = first + (last - first)/2;
        if(nums[mid] == target)
          return mid;
        if(nums[mid] > nums[last])//[f,mid] is ordered
        {
          if(target >= nums[first] && target <= nums[mid])
            last = mid;
          else
            first = mid + 1;
        }
        else//[mid,l] is ordered
        {
          if(target >= nums[mid] && target <= nums[last])
            first = (mid == first)?mid + 1:mid;
          else
            last = mid - 1;
        }
      }
      if(first == last && target == nums[first])
        return first;
      return -1;
    }
    int section2_1_3::search1(const vector<int>& nums, int target)
    {
      int first = 0;
      int last = nums.size() - 1;
      while(first != last)
      {
        const int mid = first + (last - first)/2;
        if(nums[mid] == target)
          return mid;
        if(nums[mid] >= nums[first])//[f,mid] is ordered
        {
          if(target >= nums[first] && target <= nums[mid])
            last = mid;
          else
            first = mid + 1;
        }
        else//[mid,l] is ordered
        {
          if(target >= nums[mid] && target <= nums[last])
            first = (mid == first)? mid + 1: mid;
          else
            last = mid - 1;
        }
      }
      if(first == last && target == nums[first])
        return first;
      return -1;
    }
    int section2_1_4::search(const vector<int>& nums, int target)
    {
      int first = 0;
      int last = nums.size() - 1;
      while(first != last)
      {
        const int mid = first + (last - first)/2;
        if(nums[mid] == target)
          return mid;
        if(nums[mid] > nums[last])//[f,mid] is ordered
        {
          if(target >= nums[first] && target <= nums[mid])
            last = mid;
          else
            first = mid + 1;
        }
        else if(nums[mid] < nums[last])//[mid,l] is ordered
        {
          if(target >= nums[mid] && target <= nums[last])
            first = (mid == first)?mid + 1:mid;
          else
            last = mid - 1;
        }
        else//for nums[mid] == nums[last]
          last--;
      }
      if(first == last && target == nums[first])
        return first;
      return -1;
    }
    //O(m+n)
    double section2_1_5::findMedianSortedArrays(const vector<int>& A, const vector<int>& B)
    {
      const int M = A.size();
      const int N = B.size();
      int total = M + N;
      if(total == 0)
      {
        cerr << "size of A is 0 and the same to B" << endl;
        return -1;
      }
      vector<int>::const_iterator pA = A.begin();
      vector<int>::const_iterator pB = B.begin();
      int k = total/2 + 1;
      int m = 1;
      while(k != m)
      {
        if(pA != A.end() && pB != B.end())
        {
          if(*pA < *pB)
            ++pA;
          else
            ++pB;
        }
        else if(pA != A.end() && pB == B.end())
          ++pA;
        else if(pA == A.end() && pB != B.end())
          ++pB;
        ++m;
      }
      assert(k == m);
      if(total & 0x1)//total is odd
      {
        if(pA != A.end() && pB == B.end())
          return *pA;
        else if(pA == A.end() && pB != B.end())
          return *pB;
        else
          return (*pA > *pB)? *pB: *pA;
      }
      else//total is even
      {
        if(pA != A.end() && pB == B.end())
        {
          double v_m = *pA;
          double v_m_1 = 0.0;
          if(pA != A.begin())
          {
            --pA;
            v_m_1 = *(pB - 1) > *pA ? *(pB - 1): *pA;
          }
          else
            v_m_1 = *(pB - 1);
          return (v_m + v_m_1)/2;
        }
        else if(pA == A.end() && pB != B.end())
        {
          double v_m = *pB;
          double v_m_1 = 0.0;
          if(pB != B.begin())
          {
            --pB;
            v_m_1 = *(pA - 1) > *pB ? *(pA - 1): *pB;
          }
          else
            v_m_1 = *(pA - 1);
          return (v_m + v_m_1)/2;
        }
        else
        {
          double v_m = (*pA < *pB)? *pA:*pB;
          double v_m_1 = 0.0;
          if(pA != A.begin() && pB != B.begin())
          {
            --pA;
            --pB;
            v_m_1 = (*pA > *pB) ? *pA: *pB;
          }
          else if(pA == A.begin() && pB != B.begin())
          {
            --pB;
            v_m_1 = *pB;
          }
          else
          {
            --pA;
            v_m_1 = *pA;
          }
          return (v_m + v_m_1)/2;
        }
      }
    }
    //O(log(m+n))
    double section2_1_5::findMedianSortedArrays1(const vector<int>& A, const vector<int>& B)
    {
      const int m = A.size();
      const int n = B.size();
      int total = m + n;
      if(total & 0x1)//total is odd
        return find_kth(A.begin(),m,B.begin(),n,total/2 + 1);
      else
        return (find_kth(A.begin(),m,B.begin(),n,total/2)
            + find_kth(A.begin(),m,B.begin(),n,total/2 + 1))/ 2.0;
    }
    int section2_1_6::longestConsecutive(const vector<int>& nums)
    {
      unordered_map<int,bool> used;
      for (auto i : nums) used[i] = false;//O(n)
      int longest = 0;
      for(auto i : nums)
      {
        if(used[i]) continue;
        int length = 1;
        used[i] = true;
        for(int j = i + 1; used.find(j) != used.end();++j)
        {
          used[j] = true;
          ++length;
        }
        for(int j = i - 1; used.find(j) != used.end();++j)
        {
          used[j] = true;
          ++length;
        }
        longest = max(longest,length);
      }
      return longest;
    }
    int section2_1_6::longestConsecutive1(const vector<int>& nums)
    {
      unordered_map<int,int> map;
      int size = nums.size();
      int l = 1;
      for(int i = 0; i < size; ++i)
      {
        if(map.find(nums[i]) != map.end()) continue;
        map[nums[i]] = 1;
        if(map.find(nums[i] - 1) != map.end())
          l = max(l, merge_cluster(map,nums[i] - 1, nums[i]));
        if(map.find(nums[i] + 1) != map.end())
          l = max(l,merge_cluster(map,nums[i],nums[i] + 1));
      }
      return size == 0 ? 0 : l;
    }
    int section2_1_6::merge_cluster(unordered_map<int,int>& map,int left,int right)
    {
      int upper = right + map[right] -1;
      int lower = left - map[left] + 1;
      int length = upper - lower + 1;
      map[upper] = length;
      map[lower] = length;
      return length;
    }
    vector<int> section2_1_7::two_sum(vector<int>& nums, int target)
    {
      vector<int> result;
      unordered_map<int,int> map;
      for(int i = 0; i < nums.size();++i) map[nums[i]] = i;
      for(int i = 0; i < nums.size();++i)
      {
        const int gap = target - nums[i];
    #if 0
        if(map.find(gap) != map.end() &&
            map[gap] > i)
    #endif
    #if 1
          //I think it is ok
          if(map.find(gap) != map.end())
    #endif
        {
          result.push_back(i + 1);
          result.push_back(map[gap] + 1);
          break;
        }
      }
      return result;
    }
    //穷举所有情况, 加上过滤条件, 因为非降序的，所以有排序
    vector<vector<int> > section2_1_8::three_sum(vector<int>& nums,int target)
    {
      vector<vector<int> > result;
      if(nums.size() < 3) return result;
    #if 1
      sort(nums.begin(),nums.end());//O(n^2)
    
      auto last = nums.end();
      for(auto i = nums.begin(); i < last - 2; ++i)
      {
        auto j = i+1;
        if(i > nums.begin() && *i == *(i-1)) continue;
        auto k = last-1;
        while(j < k)
        {
          if(*i + *j + *k < target)
          {
            ++j;
            while(*j == *(j-1) && j < k) ++j;//filter equalition
          }
          else if(*i + *j + *k > target)
          {
            --k;
            while(*k == *(k + 1) && j < k) --k;
          }
          else
          {
            int row[] = {*i,*j,*k};
            result.push_back(vector<int>(row,row + 3));
            ++j;
            --k;
            while(*j == *(j-1) && *k == *(k+1) && j < k) ++j;
            //while(*j == *(j-1) && *k == *(k+1) && j < k) --k;
          }
        }
      }
    #endif
    #if 0//analysis to the end, there are duplicates now !!!
        auto k = nums.end()-1;
        sort(nums.begin(),nums.end());
        for(auto i = nums.begin(); i < nums.end() - 1; ++i)
        {
            auto j = i+1;
            while(j < k)
            {
                cout << "*i: " << *i << " *j: " << *j << " *k: " << *k << " | sum: " << *i + *j + *k << endl;
                if(*i + *j + *k > target)
                {
                    --k;
                    //result.push_back(vector<int>(row,row + 3));
                }
                else if(*i + *j + *k < target)
                {
                    ++j;
                }
                else
                {
                    int rows[] = {*i,*j,*k};
                    result.push_back(vector<int>(rows,rows+3));
                    ++j;
                }
            }
        }
    #endif
      return result;
    }
    int section2_1_9::three_sum_closest(vector<int>& nums, int target)
    {
      if(nums.size() < 3) return INT_MAX;
      sort(nums.begin(),nums.end());
      auto last = nums.end();
      int result = nums[0] + nums[nums.size()-1] + nums[nums.size() - 2];
      unsigned int distance = abs(result - target);
      for(auto i = nums.begin(); i < last - 2;++i)
      {
        auto j = i + 1;
        if(i > nums.begin() && *i == *(i-1)) continue;
        auto k = last - 1;
        while(j < k)
        {
          if(abs(*i + *j + *k - target) < distance)
          {
            result = *i + *j + *k;
            distance = abs(*i + *j + *k - target);
            ++j;
            --k;
            while(*j == *(j-1) && *k == *(k+1) && j < k) continue;
          }
          else if(abs(*i + *j + *k - target) >= distance)
          {
            --k;
            while(*k == *(k+1) && j < k) continue;
          }
        }
      }
      return result;
    }
    vector<vector<int> > section2_1_10::four_sum(vector<int>& nums, int target)
    {
      vector<vector<int> > result;
      if(nums.size() < 4) return result;
      sort(nums.begin(),nums.end());
      auto last = nums.end();
      for(auto i = nums.begin(); i < last-3;++i)
      {
        for(auto k = last-1; k > i + 2; --k)
        {
          for(auto n = k - 1; n > i + 1; --n)
          {
            if(*n == *(n+1)) continue;
            auto j = i + 1;
            if(i > nums.begin() && *i == *(i-1)) continue;
            while(j < n)
            {
              if(*i + *k + *j + *n > target)
              {
                --n;
                while(*n == *(n+1) && n > i + 1) continue;
              }
              else if(*i + *k + *j + *n < target)
              {
                ++j;
                while(*j == *(j-1) && j < n) continue;
              }
              else
              {
                int row[] = {*i,*j,*n,*k};
                result.push_back(vector<int>(row,row+4));
                --n;
                ++j;
                while(*n == *(n-1) && *j == *(j-1) && j < n) continue;
              }
            }
          }
        }
      }
      return result;
    }
    vector<vector<int> > section2_1_10::four_sum_hash(vector<int>& nums, int target)
    {
      vector<vector<int> > result;
      return result;
    }
    int section2_1_11::remove_element(vector<int>& nums, int target)
    {
      int index = 0;
      for(int i = 0; i < nums.size();++i)
      {
        if(nums[i] != target)
          nums[index++] = nums[i];
      }
      return index;
    }
    int section2_1_11::remove_element2(vector<int>& nums, int target)
    {
    #if 1
      return distance(nums.begin(),remove(nums.begin(),nums.end(),target));
    #endif
    }
    void section2_1_12::next_permutation(vector<int>& nums)
    {
      if(nums.size() <= 1) return;
      int j = 0;
      int m = nums.size() - 1;
      for(int n = m-1; n > 0; --n)
      {
        if(nums[n] < nums[n-1]) continue;
        j = n - 1;
        int i;
        int med = (m+n) /2;
        while(n != m)
        {
          if(nums[med] == nums[j])
          {
            i = med + 1;
            break;
          }
          else if(nums[med] < nums[j])
          {
            m = med;
            med = (m+n)/2;
          }
          else
          {
            n = med;
            med = (m+n)/2;
          }
          if(m == n+1)
          {
            if(nums[j] > nums[m] && nums[j] < nums[n])
              i = n;
            else if(nums[j] < nums[m])
              i = m;
            break;
          }
        }
        //trans nums[i] and nums[j]
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
        m = nums.size() - 1;
        j++;
        int sum = m+j;
        int half = (m-j+1)/2 + j;
        if((m-j)&0x1) half -= 1; 
        for(;j <= half;++j)
        {
          tmp = nums[j];
          nums[j] = nums[sum-j];
          nums[sum-j] = tmp;
        }
      }
    }
    string section2_1_13::get_permutation(int n, int k)
    {
      //0. Initialization
      string s(n,'0');
      unordered_map<int,char> un_used;
      for(int i = 0; i < n; ++i)
      {
        s[i] += i+1;
        un_used[i] = s[i];
      }
      //1. Calculate factorial
      vector<int> fac(n-1,1);
      for(int i = 1; i < n-1;++i)
        fac[i] = fac[i-1] * (i+1);
      for(int i = 0; i < n;++i)
      {
        if(i == n-1)
          s[i] = un_used[0];
        //calculate index
        int times = k/fac[n-i-2];
        int index = (k % fac[n-i-2] == 0) ? times-1:times;
        s[i] = un_used[index];
        for(int j = index + 1; j < n; ++j)
        {
          un_used[j-1] = un_used[j];
          if(un_used[j] == -1)
            break;
          if(j == n-1)
            un_used[j] = -1;
        }
      }
      return s;
    }
    template<typename Sequence>
    Sequence kth_permutation(const Sequence& seq, int k)
    {
      Sequence S(seq);
    }
    bool section2_1_14::is_valid_sudoku(const vector<vector<char> >& board, vector<vector<char> >& err)
    {
      bool used[9];
      for(int i = 0; i < 9; ++i)
      {
        fill(used, used+9, false);
        //check row
        for(int j = 0; j < 9; ++j)
          if(!check(board[i][j],used))
          {
    #if 1
            //err
            for(int ERR_ROW = 0; ERR_ROW < 9; ++ ERR_ROW)
              err[i][ERR_ROW] = board[i][ERR_ROW];
    #endif
            return false;
          }
              fill(used, used+9, false);
        //check column
        for(int j = 0; j < 9; ++j)
          if(!check(board[j][i],used))
          {
    #if 1
            //err
            for(int ERR_COL = 0; ERR_COL < 9; ++ ERR_COL)
              err[ERR_COL][i] = board[ERR_COL][i];
    #endif
              return false;
          }
      }
      for(int r = 0; r < 3; ++r)
        for(int c = 0; c < 3;++c)
        {
          fill(used,used + 9, false);
          //check square
          for(int i = r * 3; i < r * 3 + 3; ++i)
            for(int j = c * 3; j < c * 3 + 3; ++j)
              if(!check(board[i][j],used))
              {
    #if 1
              //err
                for(int ii = r * 3; ii < r * 3 + 3; ++ii)
                  for(int jj = c * 3; jj < c * 3 + 3; ++jj)
                    err[ii][jj] = board[ii][jj];
    #endif
                  return false;
              }
        }
      return true;
    }
    bool section2_1_14::check(char ch, bool used[9])
    {
      if(ch == '.') return true;
      if(used[ch-'1']) return false;
      return used[ch-'1'] = true;
    }
    int section2_1_15::trap(const vector<int>& height)
    {
      if(height.size() <= 2) return 0;
      int num = height.size();
      vector<int> max_left(num,-1);
      vector<int> max_right(num,-1);
      for(int i = 1; i < num; ++i)
      {
        max_left[i] = max(max_left[i-1], height[i-1]);
        max_right[num-1-i] = max(max_right[num-i], height[num-i]);
      }
      int sum = 0;
      for(int i = 0; i < num; ++i)
      {
        int h = min(max_left[i], max_right[i]);
        if(h > height[i])
          sum += h -height[i];
      }
      return sum;
    }
    void section2_1_16::rotate(vector<vector<int> >& matrix)
    {
      const int n = matrix.size();
      //row to column
      for(int i = 0; i < n; ++i)
        for(int j = 0; j < i; ++j)
        {
          int tmp;
          tmp = matrix[i][j];
          matrix[i][j] = matrix[j][i];
          matrix[j][i] = tmp;
        }
      //i column to n-i column
      for(int j = 0; j < n/2; ++j)
      {
        for(int i = 0; i < n; ++i)
        {
          int tmp = matrix[i][j];
          matrix[i][j] = matrix[i][n-1-j];
          matrix[i][n-1-j] = tmp;
        }
      }
    }
    void section2_1_16::rotate2(vector<vector<int> >& matrix)
    {
      int a = 0;
      int b = matrix.size()-1;
      while(a<b) { 
          for(int i=0;i<b-a;i++){
              int tmp = matrix[a][i+a];
              matrix[a][i+a] = matrix[b-i][a];
              matrix[b-i][a] = matrix[b][b-i];
              matrix[b][b-i] = matrix[a+i][b];
              matrix[a+i][b] = tmp;
          }
          a++;
          b--;
      }
    }
    vector<int> section2_1_17::plus_one(vector<int>& digits)
    {
      int c = 1;
      for(auto it = digits.rbegin(); it != digits.rend();++it)
      {
        *it += c;
        c = *it / 10;
        *it %= 10;
      }
      if(c > 0) digits.insert(digits.begin(),1);
      return digits;
    }
    int section2_1_18::climb_chairs(int n)
    {
      const double s = sqrt(5);
      return floor((pow((1+s)/2, n+1) + pow((1-s)/2, n+1))/s + 0.5);
    }
    int section2_1_18::climb_chairs2(int n)
    {
      if(n<=2)
        return n;
      vector<int> res;
      res.push_back(0);
      res.push_back(1);
      res.push_back(2);
      for(int i=3;i<=n;i++)
       res.push_back(res[i-1]+res[i-2]);
      return res[n];
    }
    vector<int> section2_1_19::gray_code(int n)
    {
      vector<int> result(1);
      result[0] = n;
      return result;
    }
    void section2_1_20::set_zeros(vector<vector<int> >& matrix)
    {
      const size_t m = matrix.size();
      const size_t n = matrix[0].size();
      vector<bool> row(m, false);
      vector<bool> col(n, false);
      for(size_t i = 0; i < m; ++i)
        for(size_t j = 0; j < n; ++j)
          if(matrix[i][j] == 0)
            row[i] = col[j] =true;
      for(size_t i = 0; i < m; ++i)
        if(row[i])
          fill(&matrix[i][0], &matrix[i][0] + n, 0);
      for(size_t j = 0; j < n; ++j)
        if(col[j])
          for(size_t i = 0; i < m; ++i)
            matrix[i][j] = 0;
    }
    void section2_1_20::set_zeros1(vector<vector<int> >& matrix)
    {
      const size_t m = matrix.size();
      const size_t n = matrix[0].size();
      bool row_has_zero = false;
      bool col_has_zero = false;
      for(size_t i = 0; i < n; ++i)
        if(matrix[0][i] == 0)
        {
          row_has_zero = true;
          break;
        }
      for(size_t i = 0; i < m; ++i)
        if(matrix[i][0] == 0)
        {
          col_has_zero = true;
          break;
        }
      for(size_t i = 1; i < m; ++i)
        for(size_t j = 1; j < n; ++j)
          if(matrix[i][j] == 0)
          {
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
      for(size_t i = 1; i < m; ++i)
        for(size_t j = 1; j < n; ++j)
          if(matrix[i][0] == 0 || matrix[0][j] == 0)
            matrix[i][j] = 0;
      if(row_has_zero)
        for(size_t i = 0; i < n;++i)
          matrix[0][i] = 0;
      if(col_has_zero)
        for(size_t i = 0; i < m; ++i)
          matrix[i][0] = 0;
    }
    int section2_1_21::can_complete_circuit(vector<int>& gas, vector<int>& cost)
    {
      int total = 0;
      int j = -1;
      for(int i = 0, sum=0; i < gas.size();++i)
      {
        sum += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if(sum < 0)
        {
          j = i;
          sum = 0;
        }
      }
      return total >= 0 ? j + 1 : -1;
    }
    int section2_1_22::candy(vector<int>& ratings)
    {
      const int n = ratings.size();
      vector<int> increment(n);
      //左右各扫一遍
      for(int i = 1, inc = 1; i < n; ++i)
      {
        if(ratings[i] > ratings[i-1])
          increment[i] = max(inc++, increment[i]);
        else
          inc = 1;
      }
      for(int i = n-2, inc = 1; i >=0; i--)
      {
        if(ratings[i] > ratings[i+1])
          increment[i] = max(inc++,increment[i]);
        else
          inc = 1;
      }
      return accumulate(&increment[0], &increment[0]+n,n);
    }
    int section2_1_23::single_number(vector<int>& nums)
    {
      int result = 0;
      for(auto i : nums)
        result ^= i;
      return result;
    }
    int section2_1_24::single_number(vector<int>& nums)
    {
      const int B = sizeof(int) * 8;
      vector<int> count(B,0);
      for(int i = 0; i < nums.size();++i)
        for(int j = 0; j < B;++j)
          count[j] += (nums[i] >> j) & 1;
      int result = 0;
      for(int i = 0; i < B; ++i)
        result += ((count[i]%3) << i);
      return result;
    }
    #if 0
    list_node* section2_2_1::add_two_numbers(list_node* l1, list_node* l2)
    {
      list_node* result = NULL;//new struct(-1);
      result.next = NULL;
      list_node* head = result;
      list_node* digit1 = l1;
      list_node* digit2 = l2;
      int val1 = 0;
      int val2 = 0;
      int di = 0;
      while(digit1 != NULL || digit2 != NULL )
      {
        //invariance 2
        if(result == NULL)
          result = new struct(-1);
        else
        {
          result.next = new struct(-1);
          result = result.next;
        }
        //logic
        if(digit1 != NULL )
          val1 = digit1.val;
        if(digit2 != NULL)
          val2 = digit2.val;
        result.val = (val1 + val2 + di) % 10;
        di = (val1 + val2 + di) / 10;
        //invariance 1
        val1 = 0;
        val2 = 0;
        digit1 = digit1.next;
        digit2 = digit2.next;
      }
      if(di != 0)
      {
        result.next = new struct(di);
        result = result.next;
      }
      return head;
    }
    list_node* section2_2_2::reverse_between(list_node* head, int m, int n)
    {
      //find m and n
      list_node* s = NULL, f = NULL;
      list_node* it = head;
      for(int i = 1; i <= n; ++i)
      {
        if(i < m-1)
        {
          ++it;
          continue;
        }
        else
          s = it;
        if(i < n)
        {
          ++it;
          continue;
        }
        else
        {
          f = it;
          break;
        }
      }
      //reverse
      list_node* prev = s, c = s.next, tmp = NULL;
      while(prev != f)
      {
        if(prev == s)
        {
          prev = c;
          c = c.next;
          continue;
        }
        prev.next = NULL;
        tmp = c.next;
        c.next = prev;
        prev = c;
        c = tmp;
      }
      prev = s;
      s = s.next;
      //head and tail
      prev.next = f;
      s.next = tmp;
      return head;
    }
    list_node* section2_2_3::partion(list_node* head, int x)
    {
      list_node* l = NULL, g = NULL, it = head;
      while(it != NULL)
      {
        if(it->val < x && l == g)
        {
          l = g = it;
        }
        else if(it->val >= x && l == g)
          g = it;
        else if(it->val < x && l != g)
        {
          l = g;
          int val = g->val;
          g->val = it->val;
          it->val = val;
          if(g->.next.val >= x)
            g = g->next;
        }
      }
      return head;
    }
    
    list_node* section2_2_4::delete_duplicates(lsit_node* head)
    {
      list_node* i = head, j = head, prev = NULL;
      while(i->next != NULL)
      {
        if(j->next == NULL)
        {
          if(j == i || j->val != i->val)
            break;
          else
          {
            list_node* prev = i;
            i = i->next;
            prev->next = j;
            //delte i to x->next == j
            for(;i->next != j && i != j;)
            {
              prev = i;
              i = i->next;
              prev->next = NULL;
              delloc(prev);
            }
          }
        }
        if(j->next->val == j->val)
        {
          j = j->next;
        }
        //stop
        else
        {
          if(i == j)
            i = j = j->next;
          else
          {
            list_node* prev = i;
            i = i->next;
            prev->next = j;
            //delete i to x->next ==j 
            for(;i->next != j && i != j;)
            {
              prev = i;
              i = i->next;
              prev->next = NULL;
              delloc(prev);
            }
            i->next = NULL;
            delloc(i);
            i = j->next;
          }
        }
      }
    }
    bool section3_1::is_palindrome(string s)
    {
      bool is_pa = true;
      string s1;
      for(auto c : s)
        if(c<= 57 && c >= 48 ||
           c<= 90 && c >= 65 ||
           c<= 122 && c >= 97
           )
          s1.push_back(c);
      int len = s.lengh();
      for(int i = 0; i < num/2; ++i)
        if(s1[i] != s1[len-1-i])
        {
          is_pa = false;
          break;
        }
      return is_pa;
    }
    list_node* section2_2_6::rotate_right(list_node* head, int k)
    {
      list_node* it = head;
      list_node* h_head = head;
      list_node* tail = head;
      int num = 0;
      while(it != NULL)
      {
        if(num < k)
        {
          head = head->next;
          ++num;
        }
        else if(num == k)
        {
          list_node* tmp = head->next;
          head->next = NULL;
          head = tmp;
          tmp = NULL;
        }
        if(it->next NULL)
        {
          it->next = h_head;
          h_head = NULL;
        }
        it = it->next;
      }
      return head;
    }
    
    random_list_node* section2_2_10::copy_random_list(random_list_node* head)
    {
    #if 0
        random_list_node iter = head, next;
        // First round: make copy of each node.
        // and link them together side-by-side in a single list.
        while(iter != nullptr)
        {
            next = iter.next;
            random_list_node copy = new random_list_node(iter.label);
            iter.next = copy;
            copy.next = next;
            iter = next;
        }
    #endif
        return nullptr;
    }
    
    #endif
}
