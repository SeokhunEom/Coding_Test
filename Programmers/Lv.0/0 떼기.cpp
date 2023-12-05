#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
  string answer = "";
  int flag = 0;

  for (char c : n_str) {
    if (flag == 0 && c == '0') {
      continue;
    } else if (flag == 0 && c != '0') {
      flag = 1;
    }
    answer += c;
  }

  return answer;
}