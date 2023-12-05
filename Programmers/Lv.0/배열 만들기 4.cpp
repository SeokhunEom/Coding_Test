#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> stk;

  for (int i = 0; i < arr.size();) {
    if (stk.size() == 0 || stk.back() < arr[i]) {
      stk.push_back(arr[i]);
      i++;
    } else {
      stk.pop_back();
    }
  }

  return stk;
}