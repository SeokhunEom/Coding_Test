#include <bits/stdc++.h>
using namespace std;

int N, M, K, ans = INT_MAX;
string board[1000];
int vis[1000][1000][11];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<tuple<int, int, int>> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) cin >> board[i];

  q.push({0, 0, 0});
  vis[0][0][0] = 1;
  while (!q.empty()) {
    int x, y, k;
    tie(x, y, k) = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (board[nx][ny] == '0' && !vis[nx][ny][k]) {
        q.push({nx, ny, k});
        vis[nx][ny][k] = vis[x][y][k] + 1;
      } else if (board[nx][ny] == '1' && k < K && !vis[nx][ny][k + 1]) {
        q.push({nx, ny, k + 1});
        vis[nx][ny][k + 1] = vis[x][y][k] + 1;
      }
    }
  }

  for (int i = 0; i <= K; i++) {
    if (vis[N - 1][M - 1][i]) ans = min(ans, vis[N - 1][M - 1][i]);
  }

  cout << (ans == INT_MAX ? -1 : ans);

  return 0;
}
