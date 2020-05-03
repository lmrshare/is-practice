#include "april_algo.h"
#include <algorithm>
#include <numeric>
#include <assert.h>
#include <climits>

namespace april_algo
{
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1)
            return s.length();
        
        int P[s.length()];
        int S[s.length()];
        P[0] = 1;
        S[0] = 1;
        for (size_t i = 1; i < s.length(); ++i) {
            P[i] = P[i-1]+1;
            for (size_t j = 0; j < i; ++j) {
                if (s[j] == s[i]) {
                    P[i] = 1;
                    break;
                }
            }

            S[i] = S[i-1] > P[i] ? S[i-1] : P[i];
        }
        return S[s.length()-1];
    }
    //暂时未分类
    int leastKMakeA_B_cntA_cntB(int a, int b, int cnta, int cntb) {
        int k;
        if (cnta == 0 && cntb == 0) {
            k = -1;
        } else if (a < 2 || b < 2 || a>=b) {
            k = -1;
        } else{
            int current_a = 0;
            int current_b = 0;
            int pub = 0;
            int non = 0;
            k = 0;
            while (true) {
                if (current_a+current_b+pub >= cnta+cntb) {
                    bool break_while = false;
                    for (int ii = 0; ii <= pub; ++ii)
                        if (current_a+ii >= cnta && current_b+pub-ii >= cntb)
                            break_while = true;

                    if (break_while)
                        break;
                }
                k++;
                //non
                if (k % a == 0 && k % b == 0)
                    non++;
                //pub
                else if (k % a != 0 && k % b != 0)
                    pub++;
                //a
                else if (k % a != 0 && k % b == 0)
                    current_a++;
                //b
                else if (k % a == 0 && k % b != 0)
                    current_b++;
            }
        }
        return k;
    }
};