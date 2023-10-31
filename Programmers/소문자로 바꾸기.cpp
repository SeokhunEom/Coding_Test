#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
  string answer = "";

  for (char c : myString) {
    answer.push_back(tolower(c));
  }

  return answer;
}