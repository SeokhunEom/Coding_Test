#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";

  bool flag = true;
  for (char c : s) {
    if (flag) {
      flag = false;
      if (c == ' ') flag = true;
      answer += toupper(c);
    } else {
      if (c == ' ') flag = true;
      answer += tolower(c);
    }
  }

  return answer;
}