#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myString) {
  vector<string> answer;

  int len = myString.length();
  string s = "";
  for (int i = 0; i < len; i++) {
    if (myString[i] == 'x') {
      if (s != "") {
        answer.push_back(s);
        s = "";
      }
    } else {
      s += myString[i];
    }
  }
  if (s != "") {
    answer.push_back(s);
  }

  sort(answer.begin(), answer.end());

  return answer;
}