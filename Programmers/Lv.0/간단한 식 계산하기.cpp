#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
  int answer = 0;

  string a, b, op, s = "";
  int flag = 0;
  for (char c : binomial) {
    if (c == ' ') {
      flag++;
    } else if (flag == 0) {
      a += c;
    } else if (flag == 1) {
      op += c;
    } else {
      b += c;
    }
  }

  if (op == "+") {
    answer = stoi(a) + stoi(b);
  } else if (op == "-") {
    answer = stoi(a) - stoi(b);
  } else {
    answer = stoi(a) * stoi(b);
  }

  return answer;
}