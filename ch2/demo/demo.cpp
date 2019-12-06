#include "ch2.h"
using namespace p2;

void test_section2_1_1();
void test_section2_1_2();
void test_setction2_1_3();
void test_setction2_1_4();
void test_setction2_1_6();
void test_setction2_1_7();
void test_section2_1_8();
void test_section2_1_9();
void test_section2_1_10();
void test_section2_1_11();
void test_section2_1_12();
void test_section2_1_13();
void test_section2_1_14();
void test_section2_1_15();
void test_section2_1_16();
void test_section2_1_17();
void test_section2_1_18();
void test_section2_1_19();
void test_section2_1_20();
void test_section2_1_21();
void test_section2_1_22();
void test_section2_1_23();
void test_section2_1_24();
void test_Bonus_dpn();
void test_LRU();//2.2.14 LRU Cche
void test_swap_pairs();//2.2.8
void test_section2_2_10();
int main()
{
  test_section2_1_1();
  return 0;
}
void test_section2_1_1()
{
  cout<<"Test section2.1.1"<<endl;
  section2_1_1* C = new section2_1_1();
  vector<int> nums(0);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  int N = C->removeDuplicates(nums);
  cout<<"length: "<<N<<endl;
  for(size_t i = 0; i < N; ++i)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl<<"-------------"<<endl;
  for(size_t i = 0; i < nums.size(); ++i)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl;
  delete C;
}
void test_section2_1_2()
{
  cout<<"Test section2.1.2"<<endl;
  section2_1_2* C = new section2_1_2();
  vector<int> nums(0);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(3);
  cout<<"-------------"<<endl<<"Original length: "<<nums.size()<<endl;
  for(size_t i = 0; i < nums.size(); ++i)
  {
    cout<<nums[i]<<" ";
  }
  int N = C->removeDuplicates3(nums);
  cout<<endl<<"length: "<<N<<endl;
  for(size_t i = 0; i < N; ++i)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl;
  delete C;
}
void test_setction2_1_3()
{
  cout << "Test section2.1.3" << endl;
  section2_1_3* C = new section2_1_3();
}
void test_setction2_1_4()
{
  cout << "Test section2.1.4" << endl;
  section2_1_4* C = new section2_1_4();
}
void test_Bonus_dpn()
{
  cout<<"Test bonus_dpn"<<endl;
  Bonums_dpn* C = new Bonums_dpn();
  vector<int> nums(0);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(3);
  cout<<endl<<"Original length: "<<nums.size()<<endl;
  for(size_t i = 0; i < nums.size(); ++i)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl<<"-------------"<<endl;
  int N = C->removeDuplicates4(nums,3);
  cout<<"length: "<<N<<endl;
  for(size_t i = 0; i < N; ++i)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl<<"-------------"<<endl;
  delete C;
}
void test_setction2_1_6()
{
  vector<int> nums;
  nums.push_back(100);
  nums.push_back(4);
  nums.push_back(200);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(2);
  section2_1_6* C = new section2_1_6();
  //int longest = C->longestConsecutive(nums);
  int longest = C->longestConsecutive1(nums);
  cout << "The unsorted array is: " << endl;
  print_vector<int>(nums);
  cout << "The length of the longest consecutive elements sequence is: " << longest << endl;
}


void test_setction2_1_7()
{
  section2_1_7* C = new section2_1_7();
  vector<int> nums;
  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(11);
  nums.push_back(15);
  int target = 9;
  cout << "The array is: " << endl;
  print_vector<int>(nums);
  cout << "The target is: " << target << endl;
  vector<int> result = C->two_sum(nums,target);
  cout << "The result is: " << endl;
  print_vector<int>(result);
}
void test_section2_1_8()
{
  section2_1_8* C = new section2_1_8();
  vector<int> nums;
  nums.push_back(-1);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(-1);
  nums.push_back(-4);
  cout << "The array is:" << endl;
  print_vector<int>(nums);
  vector<vector<int> > result = C->three_sum(nums,0);
  cout << "The triplets are:" << endl;
  print_matrix<int>(result);
}
void test_section2_1_9()
{
  vector<int> S;
  S.push_back(-1);
  S.push_back(2);
  S.push_back(1);
  S.push_back(-4);
  section2_1_9* C = new section2_1_9();
  cout << "The array is: " << endl;
  print_vector<int>(S);
  int result = C->three_sum_closest(S,1);
  cout << "The sum that is closet to the target is: " << result << endl;
}
void test_section2_1_10()
{
  vector<int> S;
  S.push_back(1);
  S.push_back(0);
  S.push_back(-1);
  S.push_back(0);
  S.push_back(-2);
  S.push_back(2);
  cout << "The array is: " << endl;
  print_vector<int>(S);
  section2_1_10* C = new section2_1_10();
  //vector<vector<int> > result = C->four_sum(S,0);
  vector<vector<int> > result = C->four_sum_hash(S,0);
  cout << "The triplets are: " << endl;
  print_matrix<int>(result);
}
void test_section2_1_11()
{
  vector<int> S;
  S.push_back(1);
  S.push_back(1);
  S.push_back(3);
  S.push_back(5);
  S.push_back(-2);
#if 0
  cout << "Test C++ language: " << endl;
  cout << "size(): " << S.size() << endl;
  cout << "begin - end: " << S.end() - S.begin() << endl;
  cout << "*S.begin(): " << *(S.begin()) << endl;
  cout << "*S.end(): " << *(S.end()) << endl;
#endif
  cout << "The original array is: " << endl;
  print_vector<int>(S);
  cout << "and the length is: " << S.size() << endl;
  section2_1_11* C = new section2_1_11();
  int target = 1;
  int n_len = C->remove_element2(S,target);
  cout << "remove the element: " <<  target << endl;
  cout << "The new length is: " << n_len << endl;
}
void test_section2_1_12()
{
  section2_1_12* C = new section2_1_12();
  vector<int> nums;
  nums.push_back(6);
  nums.push_back(8);
  nums.push_back(7);
  nums.push_back(4);
  nums.push_back(3);
  nums.push_back(2);
  cout << "The original array is: " << endl;
  print_vector<int>(nums);
  cout << endl;
  C->next_permutation(nums);
  cout << "The next permutation is: " << endl;
  print_vector<int>(nums);
  cout << endl;
}
void test_section2_1_13()
{
  section2_1_13* C = new section2_1_13();
  int n, k;
  n = 4;
  k = 3;
  string result = C->get_permutation(n,k);
  cout << "The result string is:" << endl;
  cout << result << endl;
  cout << "The size of string is: " << endl;
  cout << result.size() << endl;
}
void test_section2_1_14()
{
  section2_1_14* C = new section2_1_14();
  vector<vector<char> >board(9);
  vector<vector<char> >err(9);
  for(int i = 0; i < 9; ++i)
  {
    board[i].resize(9);
    err[i].resize(9);
    for(int j = 0; j < 9; ++j)
      board[i][j] = '.';
    for(int j = 0; j < 9; ++j)
      err[i][j] = '.';
  }
  board[0][0] = '5';
  board[0][1] = '3';
  board[0][4] = '7';

  board[1][0] = '6';
  board[1][3] = '1';
  board[1][4] = '9';
  board[1][5] = '5';

  //board[2][0] = '3';
  board[2][1] = '9';
  board[2][2] = '8';
  board[2][7] = '6';
  //board[2][8] = '6';

  board[3][0] = '8';
  board[3][4] = '6';
  board[3][8] = '3';

  board[4][0] = '4';
  board[4][3] = '8';
  board[4][5] = '3';
  board[4][8] = '1';

  board[5][0] = '7';
  board[5][4] = '2';
  board[5][8] = '6';

  board[6][1] = '6';
  board[6][6] = '2';
  board[6][7] = '8';

  board[7][3] = '4';
  board[7][4] = '1';
  board[7][5] = '9';
  board[7][8] = '5';

  board[8][4] = '8';
  board[8][7] = '7';
  board[8][8] = '9';

  print_matrix<char>(board);
  bool result = C->is_valid_sudoku(board,err);
  if(result) cout << "The Sudoku is ok" << endl;
  else
  {
      cout << "The Sudoku is not valid, and the error result is:" << endl;
    print_matrix<char>(err);
  }
}
void test_section2_1_15()
{
  vector<int> A;
  A.push_back(0);
  A.push_back(1);
  A.push_back(0);
  A.push_back(2);
  A.push_back(1);
  A.push_back(0);
  A.push_back(1);
  A.push_back(3);
  A.push_back(2);
  A.push_back(1);
  A.push_back(2);
  A.push_back(1);
  section2_1_15* C = new section2_1_15();
  int result = C->trap(A);
  cout << "The water is: " << result << endl;
}
void test_section2_1_16()
{
  vector<vector<int> > in_matrix(2);
  in_matrix[0].resize(2);
  in_matrix[1].resize(2);
  in_matrix[0][0] = 1;
  in_matrix[0][1] = 2;
  in_matrix[1][0] = 3;
  in_matrix[1][1] = 4;
  cout << "The input matrix is: " << endl;
  print_matrix<int>(in_matrix);
  section2_1_16* C = new section2_1_16();
  C->rotate2(in_matrix);
  cout << "The rotated matrix is: " << endl;
  print_matrix<int>(in_matrix);
}
void test_section2_1_17()
{
  vector<int> digits;
  digits.push_back(1);
  digits.push_back(2);
  digits.push_back(3);
  digits.push_back(9);
  section2_1_17* C = new section2_1_17();
  cout << "The digits is: " << endl;
  print_vector<int>(digits);
  vector<int> result = C->plus_one(digits);
  cout << "The result is: " << endl;
  print_vector<int>(result);
}
void test_section2_1_18()
{
  section2_1_18* C = new section2_1_18();
  int input = 2;
  int output = C->climb_chairs2(input);
  cout << "Input: " << input << endl;
  cout << "Output: " << output << endl;
}
void test_section2_1_19()
{
  int n;
  cout << "Given n: " ;
  cin >> n;
  cout << endl;
  section2_1_19* C = new section2_1_19();
  vector<int> sequence = C->gray_code(n);
  cout << "The result is: " << endl;
  print_vector<int>(sequence);
}
void test_section2_1_20()
{
  int n = 3;
  int m = 4;
  vector<vector<int> >matrix(n);
  for(int i = 0; i < n; ++i)
  {
    matrix[i].resize(m);
    for(int j = 0; j < m; ++j)
      matrix[i][j] = i + j + 1;
  }
  matrix[0][2] = 0;
  matrix[2][1] = 0;
  cout << "The input matrix is: " << endl;
  print_matrix<int>(matrix);
  section2_1_20* C = new section2_1_20();
  C->set_zeros(matrix);
  cout << "The output matrix is: " << endl;
  print_matrix<int>(matrix);
}
void test_section2_1_21()
{
  vector<int> gas(4);
  vector<int> cost(4);
  gas[0] = 2;
  gas[1] = 1;
  gas[2] = 3;
  gas[3] = 3;
  cost[0] = 2;//0->1
  cost[1] = 2;//1->2
  cost[2] = 1;//2->3
  cost[3] = 1;//3->0
  section2_1_21* C = new section2_1_21();
  int index = C->can_complete_circuit(gas,cost);
  cout << "the result is: " << index << endl;
}
void test_section2_1_23()
{
  section2_1_23* C = new section2_1_23();
  vector<int> nums(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(3);
  cout << "The array is:" << endl;
  print_vector<int>(nums);
  int result = C->single_number(nums);
  cout << "The single number is:" << result << endl;
}
void test_section2_1_24()
{
  vector<int> nums(0);
  nums.push_back(1);
  nums.push_back(4);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(3);
  nums.push_back(3);
  cout << "The array is: " << endl;
  print_vector<int>(nums);
  section2_1_24* C = new section2_1_24();
  int result = C->single_number(nums);
  cout << "The single number is: " << result << endl;
}
void test_section2_1_22()
{
  vector<int> ratings(0);
  ratings.push_back(1);
  ratings.push_back(1);
  ratings.push_back(2);
  cout << "The ratings array is: " << endl;
  print_vector<int>(ratings);
  section2_1_22* C = new section2_1_22();
  int min_num = C->candy(ratings);
  cout << "The minimus candy is: " << min_num << endl;
}
void test_LRU()
{
    LRUCache* cache = new LRUCache(2);
    cache->set(1,1);
    cache->set(2,2);
    cache->get(1);
    cache->set(3,3);
    cache->get(2);
    cache->set(4,4);
    cache->get(1);
    cache->get(3);
    cache->get(4);
}

void test_section2_2_10()
{
#if 0
    random_list_node* head;
    section2_2_10* C = new section2_2_10();
    C->copy_random_list(head);
#endif
}