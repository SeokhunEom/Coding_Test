#include <queue>
#include <string>
#include <vector>

using namespace std;

int vis1[100][100];
int vis2[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;
int n, m, flag;

int solution(vector<string> maps) {
  n = maps.size();
  m = maps[0].length();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maps[i][j] == 'S') {
        q.push({i, j});
        vis1[i][j] = 0;
        break;
      }
    }
    if (!q.empty()) break;
  }

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    int x = cur.first;
    int y = cur.second;

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis1[nx][ny] != 0 || maps[nx][ny] == 'X') continue;
      if (maps[nx][ny] == 'L') {
        flag = 1;
        q = queue<pair<int, int>>();
        q.push({nx, ny});
        vis2[nx][ny] = vis1[x][y] + 1;
        break;
      }
      q.push({nx, ny});
      vis1[nx][ny] = vis1[x][y] + 1;
    }
    if (flag == 1) break;
  }

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    int x = cur.first;
    int y = cur.second;

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis2[nx][ny] != 0 || maps[nx][ny] == 'X') continue;
      if (maps[nx][ny] == 'E') return vis2[x][y] + 1;
      q.push({nx, ny});
      vis2[nx][ny] = vis2[x][y] + 1;
    }
  }

  return -1;
}