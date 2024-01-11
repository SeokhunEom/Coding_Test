#include <stdio.h>

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
  string answer = "김서방은 ";

  int i;
  int len = seoul.size();
  for (i = 0; i < len; i++) {
    if (seoul[i] == "Kim") break;
  }
  answer += to_string(i);
  answer += "에 있다";

  return answer;
}