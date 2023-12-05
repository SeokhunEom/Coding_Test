#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) {
  string answer = "";

  int len = code.length();
  for (int i = r; i < len; i += q) {
    answer += code[i];
  }

  return answer;
}