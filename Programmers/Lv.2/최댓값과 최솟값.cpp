#include <climits>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";
  string num = "";
  int min = INT_MAX;
  int max = INT_MIN;

  for (char c : s) {
    if (c == ' ') {
      int n = stoi(num);
      if (n < min) min = n;
      if (n > max) max = n;
      num = "";
    } else
      num += c;
  }
  int n = stoi(num);
  if (n < min) min = n;
  if (n > max) max = n;

  answer += to_string(min) + ' ' + to_string(max);

  return answer;
}