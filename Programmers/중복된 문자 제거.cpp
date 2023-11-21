#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
  string answer = "";
  bool ch[128] = {0};

  for (char c : my_string) {
    if (ch[c] == false) {
      answer += c;
      ch[c] = true;
    }
  }

  return answer;
}