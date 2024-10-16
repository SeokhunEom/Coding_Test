#include <iostream>
#include <queue>
using namespace std;

int R, C, curX, curY;
string s;
char board[1000][1000];
int vis1[1000][1000], vis2[1000][1000];
queue<pair<int, int>> q1, q2;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      vis1[i][j] = -1;
      vis2[i][j] = -1;
    }
  }

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    cin >> s;
    for (int j = 0; j < C; j++) {
      board[i][j] = s[j];
      if (board[i][j] == 'F') {
        q2.push({i, j});
        vis2[i][j] = 0;
      }
      if (board[i][j] == 'J') {
        q1.push({i, j});
        vis1[i][j] = 0;
      }
    }
  }

  while (!q2.empty()) {
    pair<int, int> cur = q2.front();
    q2.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
      if (vis2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      vis2[nx][ny] = vis2[cur.first][cur.second] + 1;
      q2.push({nx, ny});
    }
  }

  while (!q1.empty()) {
    pair<int, int> cur = q1.front();
    q1.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
        cout << vis1[cur.first][cur.second] + 1;
        return 0;
      }
      if (vis1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if (vis2[nx][ny] != -1 && vis2[nx][ny] <= vis1[cur.first][cur.second] + 1)
        continue;
      vis1[nx][ny] = vis1[cur.first][cur.second] + 1;
      q1.push({nx, ny});
    }
  }

  cout << "IMPOSSIBLE";

  return 0;
}
