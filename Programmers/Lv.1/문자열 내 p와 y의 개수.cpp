#include <iostream>
#include <string>
using namespace std;

bool solution(string s) {
  bool answer = true;
  int p = 0, y = 0;

  for (char c : s) {
    if (c == 'p' || c == 'P') p++;
    if (c == 'y' || c == 'Y') y++;
  }
  answer = p == y;

  return answer;
}