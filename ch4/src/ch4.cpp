#include "ch4.h"
//using namespace std;

namespace p4{

    int largest_rectangle_area(std::vector<int>& height)
  {
    stack<int> s;
    height.push_back(0);
    int result = 0;
    for(int i = 0; i < height.size();)
    {
      if(s.empty() || height[i] > height[s.top()])
        s.push(i++);
      else
      {
        int tp = s.top();
        s.pop();
          int w = (s.empty() ? i : i - s.top() - 1);
        result = max(result, height[tp] * w);
      }
    }
    return result;
  }

};
