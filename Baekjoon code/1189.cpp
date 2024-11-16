#include <iostream>
using namespace std;

int R, C, K, ans;
string s;
int board[5][5];
int vis[5][5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void func(int x, int y, int d) {
  if (d == K && x == 0 && y == C - 1) {
    ans++;
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (board[nx][ny] == 1) continue;
    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
    if (vis[nx][ny]) continue;
    vis[nx][ny] = 1;
    func(nx, ny, d + 1);
    vis[nx][ny] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C >> K;
  for (int i = 0; i < R; i++) {
    cin >> s;
    for (int j = 0; j < C; j++) {
      if (s[j] == 'T') {
        board[i][j] = 1;
      }
    }
  }
  board[R - 1][0] = 1;

  func(R - 1, 0, 1);
  cout << ans;

  return 0;
}