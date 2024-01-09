#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
  string answer = "";

  for (char c : s) {
    if (c == ' ')
      answer += ' ';
    else if (c >= 'a' && c <= 'z')
      answer += ((c + n > 'z') ? c + n - 26 : c + n);
    else
      answer += ((c + n > 'Z') ? c + n - 26 : c + n);
  }

  return answer;
}