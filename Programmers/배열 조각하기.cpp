#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
  vector<int> answer = arr;

  int len = query.size();
  for (int i = 0; i < len; i++) {
    if (i % 2 == 0) {
      answer = vector<int>(answer.begin(), answer.begin() + query[i] + 1);
    } else {
      answer = vector<int>(answer.begin() + query[i], answer.end());
    }
  }

  return answer;
}