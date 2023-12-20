#include <bits/stdc++.h>
using namespace std;

int N, M, r, c, d, ans;
int board[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void func(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  cin >> r >> c >> d;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> board[i][j];
  func();
  cout << ans;

  return 0;
}

void func(void) {
  while (1) {
    if (board[r][c] == 0) {
      board[r][c] = 2;
      ans++;
    }
    if ((r + 1 < N && board[r + 1][c] == 0) ||
        (c + 1 < M && board[r][c + 1] == 0) ||
        (r > 0 && board[r - 1][c] == 0) || (c > 0 && board[r][c - 1] == 0)) {
      d = (d + 3) % 4;
      int nx = r + dx[d];
      int ny = c + dy[d];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] != 0)
        continue;
      else {
        r = nx;
        c = ny;
      }
    } else {
      int nx = r + dx[(d + 2) % 4];
      int ny = c + dy[(d + 2) % 4];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 1)
        break;
      else {
        r = nx;
        c = ny;
      }
    }
  }
}