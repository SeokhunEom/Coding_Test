#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;
  int first = -1, last = -1, len = arr.size();

  for (int i = 0; i < len; i++) {
    if (arr[i] == 2) {
      if (first == -1) {
        first = i;
      } else {
        last = i;
      }
    }
  }

  if (first != -1 && last != -1) {
    answer = vector<int>(arr.begin() + first, arr.begin() + last + 1);
  } else if (first != -1 && last == -1) {
    answer.push_back(2);
  } else {
    answer.push_back(-1);
  }

  return answer;
}