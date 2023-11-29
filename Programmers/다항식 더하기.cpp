#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
  string answer = "";
  string temp = "";
  int a = 0, b = 0;

  for (char c : polynomial) {
    if (c == ' ') {
      if (temp == "+") {
        temp.clear();
        continue;
      } else if (temp[temp.length() - 1] == 'x') {
        if (temp.length() == 1) {
          a += 1;
        } else {
          a += stoi(temp.substr(0, temp.length() - 1));
        }
      } else {
        b += stoi(temp);
      }
      temp.clear();
    } else {
      temp += c;
    }
  }
  if (temp[temp.length() - 1] == 'x') {
    if (temp.length() == 1) {
      a += 1;
    } else {
      a += stoi(temp.substr(0, temp.length() - 1));
    }
  } else {
    b += stoi(temp);
  }
  if (a == 1) {
    answer += 'x';
  } else if (a > 1) {
    answer += to_string(a);
    answer += 'x';
  }
  if (a > 0 && b > 0) {
    answer += " + ";
  }
  if (b > 0) {
    answer += to_string(b);
  }

  return answer;
}