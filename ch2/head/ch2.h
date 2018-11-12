#ifndef CH2
#define CH2
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <list>
#include <random>
using namespace std;

    struct list_node
    {
        int val;
        list_node* next;
        list_node(int x) : val(x), next(nullptr) {};
    };
    
    struct random_list_node
    {
        int label;
        random_list_node* next;
        random_list_node* random;
        random_list_node(int label) : label(label), next(nullptr), random(nullptr) {};
    };
    

class section2_1_1
{
  public:
    //2.1.1 Remove Duplicates from Array: duplicate degree 1
    int removeDuplicates(vector<int>& nums);
    int removeDuplicates2(vector<int>& nums);
    int removeDuplicates3(vector<int>& nums);
    template<typename InIt,typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output);
};
class section2_1_2
{
  public:
    //2.1.2 Remove Duplicates which are allowed at least twice from array-----duplicate degree 2
    int removeDuplicates(vector<int>& nums);
    int removeDuplicates2(vector<int>& nums);
    // I make the function
    int removeDuplicates3(vector<int>& nums);
};
//begin----------------------
class section2_1_3
{
  public:
    //2.1.3 Search in Rotated Sorted Array
    int search(const vector<int>& nums, int target);
    int search1(const vector<int>& nums, int target);
};
class section2_1_4
{
  public:
    int search(const vector<int>& nums, int target);
};
class section2_1_5
{
  public:
    //O(m+n)
    double findMedianSortedArrays(const vector<int>& A, const vector<int>& B);
    double findMedianSortedArrays1(const vector<int>& A, const vector<int>& B);
  private:
    static int find_kth(std::vector<int>::const_iterator A, int m,
        std::vector<int>::const_iterator B, int n, int k)
    {
      return 0;
    }
};
class section2_1_6
{
  public:
    int longestConsecutive(const vector<int>& nums);
    int longestConsecutive1(const vector<int>& nums);
  private:
    int merge_cluster(unordered_map<int,int>& map,int left,int right); 
};
class section2_1_7
{
  public:
    vector<int> two_sum(vector<int>& nums, int target);
};
class section2_1_8
{
  public:
    vector<vector<int> > three_sum(vector<int>& nums,int target=0);
};
class section2_1_9{
  public:
  int three_sum_closest(vector<int>& nums, int target=0);
};
//8
class section2_1_10
{
  public:
    vector<vector<int> > four_sum(vector<int>& nums, int target=0);
    vector<vector<int> > four_sum_hash(vector<int>& nums, int target=0);
};
//9
class section2_1_11
{
  public:
    int remove_element(vector<int>& nums, int target=0);
    int remove_element2(vector<int>& nums, int target=0);
};
//10
class section2_1_12
{
  public:
    void next_permutation(vector<int>& nums);
    //写个全排列
};
//11
class section2_1_13
{
  public:
    string get_permutation(int n, int k);
  private:
    int factorial(int n);
    template<typename Sequence>
    Sequence kth_permutation(const Sequence& seq, int k);
};
//12
class section2_1_14
{
  public:
    bool is_valid_sudoku(const vector<vector<char> >& board, vector<vector<char> >& err);
  private:
    bool check(char ch, bool used[9]);
};
//13
class section2_1_15
{
  public:
  int trap(const vector<int>& height);
};
//14
class section2_1_16
{
  public:
    void rotate(vector<vector<int> >& matrix);//mine 9ms
    void rotate2(vector<vector<int> >& matrix);//better implementation 4ms
};
//15
class section2_1_17
{
  public:
    vector<int> plus_one(vector<int>& digits);
};
//16, 斐波那契数列，这道题做的不好
class section2_1_18
{
  public:
    int climb_chairs(int n);
    int climb_chairs2(int n);

};
//17: 没明白什么意思
class section2_1_19
{
  public:
    vector<int> gray_code(int n);
};
//18
class section2_1_20
{
  public:
    void set_zeros(vector<vector<int> >& matrix);
    void set_zeros1(vector<vector<int> >& matrix);
};
//19
class section2_1_21
{
  public:
    int can_complete_circuit(vector<int>& gas, vector<int>& cost);
};
//20
class section2_1_22
{
  public:
    int candy(vector<int>& ratings);
};
//21
class section2_1_23
{
  public:
    int single_number(vector<int>& nums);
};
//22
class section2_1_24
{
  public:
    int single_number(vector<int>& nums);
};

#if 0
//23//还没有做测试
class section2_2_1
{
  list_node* add_two_numbers(list_node* l1, list_node* l2);
};
//24//还没有做测试, 并且要整理其思路
class section2_2_2
{
  public:
    list_node* reverse_between(list_node* head, int m, int n);
};
//25//还没有做测试, 并且要整理其思路
class section2_2_3
{
  public:
    list_node* partion(list_node* head, int x);
};
//26//还没有测试,2_2_4和2_2_5没有本质的区别，在复习的时候再完善
class section2_2_4
{
  public:
    list_node* delete_duplicates(list_node* head);
};
//27//还没有做测试, 并且要整理其思路
class section3_1
{
  public:
    bool is_palindrome(string s);
};
class section2_2_6
{
  public:
    list_node* rotate_right(list_node* head, int k);
};
//13
class section2_1_15
{
  public:
};
#endif
//end----------------------
class Bonums_dpn
{
  public:
    //Duplicate degree is n
    //I make the function
    int removeDuplicates(vector<int>& nums, int M);
    int removeDuplicates2(vector<int>& nums, int M);
    //This function does not work
    template<typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output, int M);
    int removeDuplicates3(vector<int>& nums, int M);
    // I make the function
    int removeDuplicates4(vector<int>& nums, int M);
};
class LRUCache{
private:
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k , int v) :key(k), value(v){};
    };
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    int get(int key)
    {
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        //put cacheMap[key]->second to head
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }
    void set(int key, int value)
    {
        if(cacheMap.find(key) == cacheMap.end())
        {
            cacheMap.erase(cacheList.back().key);//list.back return element and not iterator, so utilize '.'
            cacheList.pop_back();
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
        else
        {
            cacheMap[key]->value = value;
            //put cacheMap[key]->second to head
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }
private:
    std::list<CacheNode> cacheList;
    std::unordered_map<int, std::list<CacheNode>::iterator> cacheMap;
    int capacity;
};
//2.2.8
//void print_list(list_node* head)
//{
//    list_node* c = head;
//    std::cout << std::endl;
//    while(c != nullptr)
//    {
//        std::cout << c->val << " ";
//        c = c->next;
//    }
//    std::cout << std::endl;
//}
//list_node* swap_pairs(list_node* head)
//{
//    list_node* c = head;
//    list_node* p = head;
//    while(c != nullptr && c->next != nullptr)
//    {
//        list_node* tmp = c;
//        if(c == head)
//        {
//            p = c->next;
//            head = c->next;
//            c = p;
//        }
//        else
//        {
//            p->next = c->next;
//            c = p->next;
//        }
//        //
//        tmp->next = c->next;
//        c->next = tmp;
//        //不变式
//        c = tmp->next;
//        p = tmp;
//    }
//    print_list(head);
//    return head;
//}

class section2_2_10
{
public:
    random_list_node* copy_random_list(random_list_node* head);//UNDO
};

#endif
