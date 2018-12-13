#include "ch13.h"

namespace p13
{
  int sectionn_n_n::demofunction(vector<int>& nums)
  {
    cout << "demo function" << endl;
  }
  int section13_3::minCut(const string& s)
  {
    const int n = s.size();
    int f[n+1];
    bool p[n][n];
    fill_n(&p[0][0], n * n, false);
    //the worst case is cutting by each char
    for (int i = 0; i <= n; i++)
        f[i] = n - 1 - i; //The last one f[n]=-1
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++) 
        {
            if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) 
            {
                p[i][j] = true;
                f[i] = min(f[i], f[j + 1] + 1);
            }
        }
    }
    return f[0];
   }

}
