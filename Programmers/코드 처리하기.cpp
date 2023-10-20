#include <string>
#include <vector>

using namespace std;

string solution(string code) {
  string answer = "";
  int mode = 0;

  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '1') {
      mode = mode ^ 1;
    } else if (mode == 0 && i % 2 == 0) {
      answer.push_back(code[i]);
    } else if (mode == 1 && i % 2 == 1) {
      answer.push_back(code[i]);
    }
  }

  if (answer == "") {
    answer = "EMPTY";
  }

  return answer;
}