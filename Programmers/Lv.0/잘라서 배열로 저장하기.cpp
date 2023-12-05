#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
  vector<string> answer;

  string temp = "";
  for (char c : my_str) {
    temp += c;
    if (temp.length() == n) {
      answer.push_back(temp);
      temp.clear();
    }
  }
  if (temp != "") {
    answer.push_back(temp);
  }

  return answer;
}