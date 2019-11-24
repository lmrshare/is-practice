#include<iostream>
#include<string>

using namespace std;

class Solution {
    public:

    bool exist(string str1, string str2) {
        size_t len1 = str1.size();
        size_t len2 = str2.size();
        int num = 0;
        size_t found = 0;
        for(size_t i = 0; i < str2.size(); ++i)
        {
            if(i != 0)
                found = str1.find(string(str2, i, 1), found+1);
            else
                found = str1.find(string(str2, i, 1), 0);
            if(found != string::npos)
                num++;
            else
                break;
        }
        return num == len2;
    }
    int minDistance(string word1, string word2) {
            size_t N = word1.size();
            size_t M = word2.size();
            if(N == 0)
                return M;
            else if(M == 0)
                return N;
            string S[M];
            for(size_t i = 0; i < M; ++i)
            {
                int pre = 0;
                string ch(word2, i, 1);
                string str = ch;
                if(i != 0) {
                    pre = i-1;
                    str = S[pre] + ch;
                }
                if(exist(word1, str))
                    S[i] = str;
                else if(exist(word1,ch) && S[pre].size() < 1)
                    S[i] = ch;
                else
                    S[i] = "";
            }
            return M+N-2*S[M-1].size();
    }

};

int main()
{
    Solution *c = new Solution();
    int N = c->minDistance("park", "spake");
    cout << "N:" << N << endl;
    delete c;
    return 0;
}
