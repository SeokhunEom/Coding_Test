#include <iostream>
using namespace std;

int N, flag;
int board[64][64];
string s;

void func(int startX, int startY, int endX, int endY) {
  if (startX + 1 == endX) {
    cout << board[startX][startY];
    return;
  }

  flag = board[startX][startY];
  for (int i = startX; i < endX; i++) {
    for (int j = startY; j < endY; j++) {
      if (flag != board[i][j]) {
        flag = -1;
        break;
      }
    }
    if (flag == -1) break;
  }
  if (flag != -1) {
    cout << flag;
    return;
  }

  cout << "(";
  func(startX, startY, (startX + endX) / 2, (startY + endY) / 2);
  func(startX, (startY + endY) / 2, (startX + endX) / 2, endY);
  func((startX + endX) / 2, startY, endX, (startY + endY) / 2);
  func((startX + endX) / 2, (startY + endY) / 2, endX, endY);
  cout << ")";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < N; j++) {
      board[i][j] = s[j] - '0';
    }
  }

  func(0, 0, N, N);

  return 0;
}