#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0, num;
  string temp = "";

  for (char c : s) {
    if (c == ' ') {
      if (temp == "Z") {
        temp = "";
        answer -= num;
      } else {
        num = stoi(temp);
        temp = "";
        answer += num;
      }
    } else {
      temp += c;
    }
  }

  if (temp == "Z") {
    answer -= num;
  } else {
    num = stoi(temp);
    answer += num;
  }

  return answer;
}