#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[1000][1000];
int dist[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) {
        q.push({i, j});
        board[i][j] = 0;
        dist[i][j] = 0;
      } else if (board[i][j] == 0) {
        dist[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == 0 || dist[nx][ny] > 0) continue;
      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << dist[i][j] << ' ';
    cout << '\n';
  }

  return 0;
}
