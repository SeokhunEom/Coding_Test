#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;

  int len = arr.size();
  for (int i = 0; i < len; i++) {
    if (answer.size() == 0) {
      answer.push_back(arr[i]);
    } else if (answer.back() == arr[i]) {
      answer.pop_back();
    } else {
      answer.push_back(arr[i]);
    }
  }

  if (answer.size() == 0) {
    answer.push_back(-1);
  }

  return answer;
}