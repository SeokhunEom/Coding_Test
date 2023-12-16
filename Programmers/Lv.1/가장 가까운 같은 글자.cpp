#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
  vector<int> answer;
  vector<int> v(26, -1);

  int len = s.length();
  for (int i = 0; i < len; i++) {
    int idx = s[i] - 'a';
    if (v[idx] == -1) {
      answer.push_back(-1);
    } else {
      answer.push_back(i - v[idx]);
    }
    v[idx] = i;
  }

  return answer;
}