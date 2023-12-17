#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;
  int a = 0, b = 0;
  char x = '\0';

  for (char c : s) {
    if (x == '\0') x = c;
    if (c == x)
      a++;
    else
      b++;
    if (a == b) {
      answer++;
      a = 0;
      b = 0;
      x = '\0';
    }
  }
  if (a != b) answer++;

  return answer;
}