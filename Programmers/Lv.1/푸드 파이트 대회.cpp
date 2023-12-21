#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
  string answer = "";

  int len = food.size();
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < food[i] / 2; j++) {
      answer += (i + '0');
    }
  }
  answer += '0';
  for (int i = len - 1; i >= 1; i--) {
    for (int j = 0; j < food[i] / 2; j++) {
      answer += (i + '0');
    }
  }

  return answer;
}