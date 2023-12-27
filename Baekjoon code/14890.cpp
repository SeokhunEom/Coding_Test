#include <bits/stdc++.h>
using namespace std;

int N, L, ans;
int board[100][100];
int temp[100];

void func(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> L;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> board[i][j];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) temp[j] = board[i][j];
    func();
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) temp[j] = board[j][i];
    func();
  }
  cout << ans;

  return 0;
}

void func(void) {
  int height = temp[0];
  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (temp[i] == height)
      cnt++;
    else if (temp[i] == height + 1 && cnt >= L) {
      height++;
      cnt = 1;
    } else if (height - 1 == temp[i] && cnt >= 0) {
      height--;
      cnt = 1 - L;
    } else
      return;
  }
  if (cnt < 0) return;
  ans++;
}