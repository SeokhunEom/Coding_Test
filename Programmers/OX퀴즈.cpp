#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
  vector<string> answer;

  for (string str : quiz) {
    stringstream ss(str);
    string x, y, z;
    string op = "", eq = "";
    ss >> x >> op >> y >> eq >> z;

    if (op[0] == '+') {
      if (stoi(x) + stoi(y) == stoi(z)) {
        answer.push_back("O");
      } else {
        answer.push_back("X");
      }
    } else if (op[0] == '-') {
      if (stoi(x) - stoi(y) == stoi(z)) {
        answer.push_back("O");
      } else {
        answer.push_back("X");
      }
    }
  }

  return answer;
}