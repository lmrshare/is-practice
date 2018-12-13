#include "linear_structure.h"

namespace ls
{
    void printvector(const vector<int>& res)
    {
        cout << "[";
        for(auto & val : res)
            cout << val << ", ";
        cout << "]";
    }
    string lc344::reverseString(string s)
    {
        size_t n = s.size();
        if(n <= 1) return s;
        for(int i = 0; i < n/2; ++i)
        {
            char c = s[i];
            s[i] = s[n-1-i];
            s[n-1-i] = c;
        }
        return s;
    }
    string lc344::reverseString1(string s)
    {
        size_t n = s.size();
        if(n <= 1) return s;
        string::iterator start = s.begin();
        string::iterator finish = s.end()-1;
        while(start <= finish)
        {
            char c = *start;
            char t = *finish;
            *start++ = *finish;
            *finish-- = c;
        }
        return s;
    }
    string lc344::reverseString2(string s)
    {
        return string(s.rbegin(), s.rend());
    }
    char* lc344::reverseString(char* s) 
    {
        int len = strlen(s);
        int i;
        char* tmp;
        
        tmp = (char*)malloc(sizeof(char)*(len+1));
        
        for(i = 0;i < len; i++)
            tmp[i] = s[len - i - 1];
        tmp[len] = '\0';
        
        return tmp;
    }
    vector<int> lc763::partitionLabels(string S)
    {
        size_t n = S.size();
        if(n <= 1) return vector<int>(n, n);
        string::iterator cb = S.end()-1;
        string::iterator p = cb-1;
        vector<int> res(1, 1);
        bool in_the_subprob;
        size_t i;
        while(cb != S.begin())
        {
            in_the_subprob = false;
            i = 0;//count the relative pos to cb
            while(cb < S.end())
            {
                if(*p == *cb) 
                {
                    in_the_subprob = true;
                    break;
                }
                ++i;
                cb++;
            }
            if(in_the_subprob)
            {
                int j = 0;
                int len = 0;
                for(; j < res.size(); ++j)
                {
                    len += res[j];
                    if(i+1 <= len) break;
                }
                res.erase(res.begin(), res.begin()+j+1);
                res.insert(res.begin(), len+1);
            }
            else
                res.insert(res.begin(), 1);
            cb = p--;
        }
        return res;
    }
}
