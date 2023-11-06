#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
  vector<int> answer = arr;

  int len = arr.size();
  if (len % 2 == 0) {
    for (int i = 1; i < len; i += 2) {
      answer[i] += n;
    }
  } else {
    for (int i = 0; i < len; i += 2) {
      answer[i] += n;
    }
  }

  return answer;
}