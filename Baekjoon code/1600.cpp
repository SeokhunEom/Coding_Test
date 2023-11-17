#include <bits/stdc++.h>
using namespace std;

int K, W, H, ans = 1000000;
int board[201][201];
int dist[201][201][32];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dx2[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy2[8] = {1, -1, 2, -2, 2, -2, 1, -1};
queue<tuple<int, int, int>> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K;
  cin >> W >> H;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> board[i][j];
      for (int k = 0; k <= K; k++) {
        dist[i][j][k] = -1;
      }
    }
  }

  q.push({0, 0, 0});
  dist[0][0][0] = 0;
  while (!q.empty()) {
    int x = get<0>(q.front());
    int y = get<1>(q.front());
    int k = get<2>(q.front());
    q.pop();
    if (k < K) {
      for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx2[dir];
        int ny = y + dy2[dir];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (board[nx][ny] == 1 || dist[nx][ny][k + 1] != -1) continue;
        q.push({nx, ny, k + 1});
        dist[nx][ny][k + 1] = dist[x][y][k] + 1;
      }
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if (board[nx][ny] == 1 || dist[nx][ny][k] != -1) continue;
      q.push({nx, ny, k});
      dist[nx][ny][k] = dist[x][y][k] + 1;
    }
  }

  for (int i = 0; i <= K; i++) {
    if (dist[H - 1][W - 1][i] == -1) continue;
    if (ans > dist[H - 1][W - 1][i]) {
      ans = dist[H - 1][W - 1][i];
    }
  }

  cout << (ans == 1000000 ? -1 : ans);

  return 0;
}
