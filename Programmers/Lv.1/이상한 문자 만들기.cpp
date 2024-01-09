#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";

  bool isUpper = true;
  for (char c : s) {
    if (c == ' ') {
      isUpper = true;
      answer += c;
      continue;
    }
    if (isUpper)
      answer += toupper(c);
    else
      answer += tolower(c);
    isUpper = !isUpper;
  }

  return answer;
}