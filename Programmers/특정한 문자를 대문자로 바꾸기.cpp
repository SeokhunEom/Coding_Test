#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
  string answer = "";

  for (char c : my_string) {
    if (c == alp[0]) {
      answer.push_back(toupper(c));
    } else {
      answer.push_back(c);
    }
  }

  return answer;
}