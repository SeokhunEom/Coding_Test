#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
  string answer = "";

  for (char c : s) {
    for (int i = 0; i < index; i++) {
      c += 1;
      if (c > 'z') c = 'a';
      for (char d : skip) {
        if (c == d) {
          i--;
          break;
        }
      }
    }
    answer += c;
  }

  return answer;
}