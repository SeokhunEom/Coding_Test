#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
  string answer = "";

  for (char c : myString) {
    if (c == 'a' || c == 'A') {
      answer.push_back('A');
    } else {
      answer.push_back(tolower(c));
    }
  }

  return answer;
}