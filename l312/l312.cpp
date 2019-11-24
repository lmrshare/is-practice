#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        size_t N = nums.size();
        if(N == 0)
            return 0;
        if(N == 1)
            return nums[0];
        int T[N][N];
        memset(T, 0, sizeof(T));
        //print((int*)T, N, N);
        for(int c=1; c<=N; ++c)
            for(int i=0; i<=N-c; ++i)
            {
                int j = i+c-1;
                if(c == 1)
                {
                    if(i == 0)
                    {
                        T[i][j] = nums[i] * nums[i+1];

                    }
                    else if(i == N-1)
                    {
                        T[i][j] = nums[i-1] * nums[i];
                    }
                    else
                        T[i][j] = nums[i-1] * nums[i] * nums[i+1];
                    continue;
                }
                for(int k = i; k<=j; ++k)
                {
                    int l_val;
                    if(i-1 < 0) l_val = 1;
                    else l_val = nums[i-1];

                    int r_val;
                    if(j+1 >= N) r_val = 1;
                    else r_val = nums[j+1];

                    int tmp;
                    if(k == i)
                       tmp = l_val * nums[i] * r_val + T[i+1][j];
                    else if(k == j)
                       tmp = l_val * nums[j] * r_val + T[i][j-1];
                    else
                       tmp = l_val * nums[k] * r_val + T[i][k-1] + T[k+1][j];
                    if(tmp > T[i][j])
                        T[i][j] = tmp;
                }
            }
        return T[0][N-1];
    }
    //the output is right, but it is out of memory
    int maxCoins_bak(vector<int>& nums)
    {
        //cout << "1\n";
        size_t N = nums.size();
        if(N == 0)
            return 0;
        if(N == 1)
            return nums[0];
        //cout << "set\n";
        //int T[N+1][N+1][N][N];
        vector<vector<vector<vector<int> > > > T(N+1,
                                                 vector<vector<vector<int> > >(N+1, vector<vector<int> >(N, vector<int>(N, 0))));
        //cout << "2\n";
        for(int j = 0; j<N; ++j)
        {
            for(int i = j; i>=0; --i)
            {
                //cout << "[i, j]: " << i << ", "  << j <<endl;
                for(int l = i-1; l >= -1;--l)
                {
                    for(int r = j+1; r <= N;++r)
                    {
                        //cout << "3\n";
                        int l_final = l;
                        if(l_final == -1) l_final = N;
                        int r_final = r;

                        int l_val, r_val;
                        if(l == -1) l_val = 1;
                        else l_val = nums[l];
                        if(r == N) r_val = 1;
                        else r_val = nums[r];

                        //cout << "0 [i, j, l, r]: " << i << ", "  << j << ", " << l << ", " << r <<endl;
                        if(i == j)
                        {
                            T[r_final][l_final][i][j] = l_val * nums[i] * r_val;
                            continue;
                        }
                        //cout << "1 [i, j, l, r]: " << i << ", "  << j << ", " << l << ", " << r <<endl;
                        for(int k = i; k<=j; ++k)
                        {
                            //cout << "[i, k, j, l, r]: " << i << ", " << k << ", " << j << ", " << l << ", " << r <<endl;
                            int tmp;
                            if(k == i)
                                tmp = l_val * nums[i] * r_val + T[r_final][i][i+1][j];
                            else if(k == j)
                                tmp = l_val * nums[j] * r_val + T[j][l_final][i][j-1];
                            else
                                tmp = l_val * nums[k] * r_val + T[k][l_final][i][k-1] + T[r_final][k][k+1][j];
                            if(tmp > T[r_final][l_final][i][j])
                                T[r_final][l_final][i][j] = tmp;
                        }
                    }
                }
            }
        }
        return T[N][N][0][N-1];
    }
    void print(int *P, int N, int M) {
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                // if(*(P + i * N + j) != 0)
                //     cout << "error\n";
                cout << *(P + i * N + j) << "; ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution *c = new Solution();
#if 0
    int vals[] = {54,88,26,48,9 ,33, 0,66, 4,82,66,7 ,28,23,73,99,44,27,16,29,52,66,30,97,41,33,60,62,45,40,19,35,
                  97,69,19,60,2 ,48,81,66,45,86,51,51,47,97,5 ,59,54,98,79,90,70,70,62,16,96,95,97,77,21,35,10,90,
                  14,31,21,29,40,81,33,64,91,44,81,85,77,9 ,67,58,77,88,69,76,89,33,36,87,85,77,94,96,37,61,23,75,
                  15,29,21,88,91};
#endif
#if 1
    int vals[] = {3, 1, 5, 8};
#endif
    int N = sizeof(vals)/sizeof(int);
    vector<int> nums(vals, vals+N);
    int points = c->maxCoins(nums);

    cout << "points: " << points << endl;
    delete c;
    return 0;
}
