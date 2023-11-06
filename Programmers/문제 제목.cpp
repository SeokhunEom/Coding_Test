#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
  vector<int> answer;

  int len = flag.size();
  for (int i = 0; i < len; i++) {
    if (flag[i] == true) {
      for (int j = 0; j < 2 * arr[i]; j++) {
        answer.push_back(arr[i]);
      }
    } else {
      for (int j = 0; j < arr[i]; j++) {
        answer.pop_back();
      }
    }
  }

  return answer;
}