#include "linear_structure.h"
#include <functional>
#include <stack>

namespace ls
{
    void printvector(const vector<int>& res)
    {
        cout << "[";
        for(auto & val : res)
            cout << val << ", ";
        cout << "]";
    }
    void printListNode(ListNode* res)
    {
        cout << "[" << endl;
        while(res != nullptr)
        {
            cout << res->val << ", ";
            res = res->next;
        }
        cout << "]" << endl;
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
    ListNode* lc876::middleNode(ListNode* head)
    {
        if(nullptr == head || nullptr == head->next) return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(nullptr != fast)
        {
            fast = fast->next;
            if(nullptr != fast) fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    int lc817::numComponents(ListNode* head, vector<int>& G)
    {
        size_t n = G.size();
        if(nullptr == head || 0 == n) return 0;
        while(nullptr != head)
        {
            link_component[vector<int>{head->val, head->val}] = true;
            if(nullptr != head->next)
                link_component[vector<int>{head->val, head->next->val}] = true;
            head = head->next;
        }
        int res = 0;
        int i = 0;
        while(!G.empty())
        {
            vector<int>::iterator it = G.begin()+i;
            if(it < G.end()-1)//at least two elements
            {
                for(int j=1; it+j < G.end(); ++j)
                {
                    if(link_component[vector<int>{*it, *(it+j)}])
                    {
                        res++;
                        G.erase(it, it+2);
                        break;
                    }
                }
                ++i;
            }
            else
            {
                while(!G.empty())
                {
                    res++;
                    G.erase(it);
                    it = G.end()-1;
                }
            }
        }
        return res;
    }
    int lc682::calPoints(vector<string>& ops)
    {
        size_t n = ops.size();
        if(1 == n && ("C" == ops[0] || "D" == ops[0] || "+" == ops[0])) return 0;
        stack<int> s;
        for(size_t i = 0; i < n; ++i)
        {
            if("+" == ops[i])
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                s.push(val2);
                s.push(val1);
                s.push(val1+val2);
            }
            else if("C" == ops[i])
                s.pop();
            else if("D" == ops[i])
                s.push(s.top()*2);
            else
                s.push(stoi(ops[i]));
        }
        int sum = 0;
        while(!s.empty())
        {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
    int lc921::minAddToMakeValid(string S)
    {
        if(0 == S.size()) return 0;
        stack<char> ls;//only store "("
        int res = 0;
        for(auto & c : S)
        {
            switch(c)
            {
                case '(':
                    ls.push('(');
                    break;
                case ')':
                    if(ls.empty()) res++;
                    else ls.pop();
                    break;
                default:
                    return -1;
            }
        }
        res += ls.size();
        return res;
    }
    ListNode* lcc2::addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(nullptr == l1) return l2;
        if(nullptr == l2) return l1;
        ListNode *res = nullptr;
        ListNode *c = nullptr;
        int flag = 0;
        while(nullptr != l1 || nullptr != l2)
        {
            if(nullptr == res)
            {
                res = new ListNode(0);
                c = res;
            }
            else
            {
                c->next = new ListNode(0);
                c = c->next;
            }

            if(nullptr != l1)
            {
                flag += l1->val;
                l1 = l1->next;
            }
            if(nullptr != l2)
            {
                flag += l2->val;
                l2 = l2->next;
            }
            if(flag >= 10)
            {
                c->val = flag-10;
                flag = 1;
            }
            else
            {
                c->val = flag;
                flag = 0;
            }
        }
        if(flag > 0)
            c->next = new ListNode(flag);
        return res;
    }
}
