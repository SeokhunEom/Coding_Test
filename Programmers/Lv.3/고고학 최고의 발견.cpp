#include <string>
#include <vector>

using namespace std;

int len;
int answer = 1000000;

void rotate(int i, int j, vector<vector<int>> &clockHands);
void func1(int idx, int cnt, vector<vector<int>> clockHands);
void func2(int idx, int cnt, vector<vector<int>> clockHands);

void rotate(int i, int j, vector<vector<int>> &clockHands) {
  if (i > 0) clockHands[i - 1][j] = (clockHands[i - 1][j] + 1) % 4;
  if (i < len - 1) clockHands[i + 1][j] = (clockHands[i + 1][j] + 1) % 4;
  if (j > 0) clockHands[i][j - 1] = (clockHands[i][j - 1] + 1) % 4;
  if (j < len - 1) clockHands[i][j + 1] = (clockHands[i][j + 1] + 1) % 4;
  clockHands[i][j] = (clockHands[i][j] + 1) % 4;
}

void func1(int idx, int cnt, vector<vector<int>> clockHands) {
  if (idx == len) {
    func2(1, cnt, clockHands);
    return;
  }
  func1(idx + 1, cnt, clockHands);
  rotate(0, idx, clockHands);
  func1(idx + 1, cnt + 1, clockHands);
  rotate(0, idx, clockHands);
  func1(idx + 1, cnt + 2, clockHands);
  rotate(0, idx, clockHands);
  func1(idx + 1, cnt + 3, clockHands);
}

void func2(int idx, int cnt, vector<vector<int>> clockHands) {
  if (idx == len) {
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        if (clockHands[i][j] != 0) return;
      }
    }
    answer = min(answer, cnt);
    return;
  }
  for (int i = 0; i < len; i++) {
    int t = 4 - clockHands[idx - 1][i];
    if (t == 4) t = 0;
    for (int j = 0; j < t; j++) {
      rotate(idx, i, clockHands);
      cnt++;
    }
  }
  func2(idx + 1, cnt, clockHands);
}

int solution(vector<vector<int>> clockHands) {
  len = clockHands.size();
  func1(0, 0, clockHands);

  return answer;
}