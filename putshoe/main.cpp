#include <iostream>
#include <vector>
using namespace std;

struct soldier
{
    int len;
    soldier(int _len): len(_len){};
};

struct shoe
{
    int len;
    shoe(int _len): len(_len){};
};

vector<vector<int> > puton_shoes(vector<soldier*>& S, vector<shoe*>& P);
int f(const soldier* s, const shoe* p);
int main()
{
    int n = 10;
    vector<soldier*> S(n, new struct soldier(0));
    vector<shoe*> P(n, new struct shoe(0));
    for(int i = 1; i <= n; ++i)
    {
        S[i]->len = i;
        P[i]->len = i;
    }

    return 0;
}

vector<vector<int> > puton_shoes(vector<soldier*>& S, vector<shoe*>& P)
{

}
int f(const soldier* s, const shoe* p)
{
    return s->len - p->len;
}
