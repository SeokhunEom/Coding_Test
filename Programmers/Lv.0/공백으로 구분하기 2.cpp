#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
  vector<string> answer;

  string s;
  int len = my_string.length();
  for (int i = 0; i < len; i++) {
    if (my_string[i] == ' ') {
      if (s != "") {
        answer.push_back(s);
        s = "";
      }
    } else if (i == len - 1) {
      s += my_string[i];
      answer.push_back(s);
    } else {
      s += my_string[i];
    }
  }

  return answer;
}