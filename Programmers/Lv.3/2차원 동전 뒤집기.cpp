#include <string>
#include <vector>

using namespace std;

int len1, len2, len;
int answer = 100;

void func(int idx, int cnt, vector<vector<int>> v,
          vector<vector<int>> &target) {
  if (idx == len) {
    bool flag = true;
    for (int i = 0; i < len1; i++) {
      for (int j = 0; j < len2; j++) {
        if (v[i][j] != target[i][j]) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) answer = min(answer, cnt);
  } else if (idx < len1) {
    func(idx + 1, cnt, v, target);
    for (int i = 0; i < len2; i++) v[idx][i] = 1 - v[idx][i];
    func(idx + 1, cnt + 1, v, target);
  } else {
    func(idx + 1, cnt, v, target);
    for (int i = 0; i < len1; i++) v[i][idx - len1] = 1 - v[i][idx - len1];
    func(idx + 1, cnt + 1, v, target);
  }
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
  len1 = beginning.size();
  len2 = beginning[0].size();
  len = len1 + len2;

  func(0, 0, beginning, target);
  if (answer == 100) answer = -1;

  return answer;
}