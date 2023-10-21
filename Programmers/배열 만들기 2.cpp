#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
  vector<int> answer;

  for (int i = l; i <= r; i++) {
    string s = to_string(i);
    int n = 0;

    for (int j = 0; j < s.size(); j++) {
      if (s[n] == '0' || s[n] == '5') {
        n++;
      }
    }
    if (n == s.size()) {
      answer.push_back(i);
    }
  }

  if (answer.size() == 0) {
    answer.push_back(-1);
  }

  return answer;
}