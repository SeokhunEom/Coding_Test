#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
  int answer = 2;

  bool flag = true;
  for (string str1 : dic) {
    flag = true;
    for (string str2 : spell) {
      if (str1.find(str2) == -1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      answer = 1;
      break;
    }
  }

  return answer;
}