#include <queue>
#include <string>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[100][100];
int n, m, gx, gy, rx, ry;
queue<pair<pair<int, int>, int>> q;

int solution(vector<string> board) {
  int answer = 1000000;

  int n = board.size();
  int m = board[0].length();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'R') {
        rx = i;
        ry = j;
      } else if (board[i][j] == 'G') {
        gx = i;
        gy = j;
      }
    }
  }

  q.push({{rx, ry}, 0});
  vis[rx][ry] = true;
  while (!q.empty()) {
    pair<pair<int, int>, int> cur = q.front();
    int cx = cur.first.first;
    int cy = cur.first.second;
    int cnt = cur.second;
    q.pop();

    if (cx == gx && cy == gy) answer = min(answer, cnt);

    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'D')
        continue;

      while (1) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'D') {
          nx -= dx[dir];
          ny -= dy[dir];
          break;
        }
      }
      if (vis[nx][ny]) continue;

      vis[nx][ny] = true;
      q.push({{nx, ny}, cnt + 1});
    }
  }

  return answer == 1000000 ? -1 : answer;
}