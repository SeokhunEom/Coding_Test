#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
  vector<string> answer;

  for (string row : picture) {
    for (int i = 0; i < k; i++) {
      string str = "";
      for (char c : row) {
        for (int j = 0; j < k; j++) {
          str += c;
        }
      }
      answer.push_back(str);
    }
  }

  return answer;
}