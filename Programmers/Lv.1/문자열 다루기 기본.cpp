#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
  bool answer = false;

  int len = s.length();
  if (len == 4 || len == 6) {
    for (char c : s) {
      if (c < '0' || c > '9') return false;
    }
    answer = true;
  }

  return answer;
}