#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
  int answer = 0;

  string temp = "";
  for (char c : my_string) {
    if (c >= '0' && c <= '9') {
      temp += c;
    } else {
      if (temp != "") {
        answer += stoi(temp);
        temp = "";
      }
    }
  }
  if (temp != "") {
    answer += stoi(temp);
    temp = "";
  }

  return answer;
}