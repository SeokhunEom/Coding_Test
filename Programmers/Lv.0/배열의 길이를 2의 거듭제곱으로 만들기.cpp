#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer = arr;

  int len = arr.size();
  int targetLen = 1;
  while (targetLen < len) {
    targetLen *= 2;
  }
  for (int i = len; i < targetLen; i++) {
    answer.push_back(0);
  }

  return answer;
}