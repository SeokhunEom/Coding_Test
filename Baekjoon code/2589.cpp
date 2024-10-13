#include <iostream>
#include <queue>
using namespace std;

int N, M, ans;
string s;
int board[50][50];
int vis[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      if (s[j] == 'W') {
        board[i][j] = 1;
      } else {
        board[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 1) continue;
      queue<pair<int, int>> q;
      for (int a = 0; a < N; a++) {
        for (int b = 0; b < M; b++) {
          vis[a][b] = -1;
        }
      }

      q.push({i, j});
      vis[i][j] = 0;

      while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];
          if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
          if (board[nx][ny] == 1 || vis[nx][ny] != -1) continue;
          q.push({nx, ny});
          vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
      }

      for (int a = 0; a < N; a++) {
        for (int b = 0; b < M; b++) {
          ans = max(ans, vis[a][b]);
        }
      }
    }
  }

  cout << ans;

  return 0;
}