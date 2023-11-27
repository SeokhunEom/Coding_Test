#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
  int answer = 0;
  vector<int> num;
  vector<char> op;
  string temp = "";

  for (char c : my_string) {
    if (c == ' ') {
      if (temp == "+") {
        op.push_back('+');
      } else if (temp == "-") {
        op.push_back('-');
      } else {
        num.push_back(stoi(temp));
      }
      temp = "";
    } else {
      temp += c;
    }
  }
  if (temp == "+") {
    op.push_back('+');
  } else if (temp == "-") {
    op.push_back('-');
  } else {
    num.push_back(stoi(temp));
  }

  answer = num[0];
  int len = op.size();
  for (int i = 0; i < len; i++) {
    if (op[i] == '+') {
      answer += num[i + 1];
    } else {
      answer -= num[i + 1];
    }
  }

  return answer;
}