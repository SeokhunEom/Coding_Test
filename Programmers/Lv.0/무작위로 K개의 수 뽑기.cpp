#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
  vector<int> answer;

  int len = arr.size();
  for (int i = 0; i < len; i++) {
    if (answer.size() == k) {
      break;
    }
    if (find(answer.begin(), answer.end(), arr[i]) == answer.end()) {
      answer.push_back(arr[i]);
    }
  }

  while (answer.size() < k) {
    answer.push_back(-1);
  }

  return answer;
}