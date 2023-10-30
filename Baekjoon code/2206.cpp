#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];
int dist[1001][1001][2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M;
queue<tuple<int, int, int>> q;
string str;

int bfs(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
  cout << bfs();

  return 0;
}

int bfs(void) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dist[i][j][0] = -1;
      dist[i][j][1] = -1;
    }
  }
  q.push({0, 0, 0});
  dist[0][0][0] = 1;
  dist[0][0][1] = 1;

  while (!q.empty()) {
    int x, y, z;
    tie(x, y, z) = q.front();
    q.pop();
    if (x == N - 1 && y == M - 1) return dist[x][y][z];

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (board[nx][ny] == '0' && dist[nx][ny][z] == -1) {
        dist[nx][ny][z] = dist[x][y][z] + 1;
        q.push({nx, ny, z});
      }
      if (z == 0 && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
        dist[nx][ny][1] = dist[x][y][0] + 1;
        q.push({nx, ny, 1});
      }
    }
  }
  return -1;
}