#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
  int answer = 0;

  for (string s : babbling) {
    int len = s.length();
    int flag = -1;
    bool result = true;
    for (int i = 0; i < len; i++) {
      if (s.substr(i, 3) == "aya" && flag != 0) {
        flag = 0;
        i += 2;
      } else if (s.substr(i, 2) == "ye" && flag != 1) {
        flag = 1;
        i += 1;
      } else if (s.substr(i, 3) == "woo" && flag != 2) {
        flag = 2;
        i += 2;
      } else if (s.substr(i, 2) == "ma" && flag != 3) {
        flag = 3;
        i += 1;
      } else {
        result = false;
        break;
      }
    }
    if (result == true) answer++;
  }

  return answer;
}