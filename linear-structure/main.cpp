#include "linear_structure.h"

//Pointers
void testlc344();
void testlc763();
//LinkedList

//Queue, Deque

//Stack

int main()
{
    testlc763();
    return 0;
}
void testlc344()
{
    ls::lc344 *C = new ls::lc344();
    string s("A man\na plan\ncanal: Panama");
    string res = C->reverseString1(s);
    cout << "Output:\n" << res << endl;
}
void testlc763()
{
    ls::lc763 *C = new ls::lc763();
    string S("ababcbacadefegdehijhklij");
    vector<int> result = C->partitionLabels(S);
    cout << endl;
    ls::printvector(result);
    cout << endl;
}
