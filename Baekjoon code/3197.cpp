#include <iostream>
#include <queue>
using namespace std;

int R, C, X1, Y1, X2, Y2, ans, idx;
char board[1500][1500];
bool visited[1500][1500];
string s;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q1, q2, tq1, tq2;
bool isFinished;

void bfs1() {
  while (!q1.empty()) {
    pair<int, int> cur = q1.front();
    q1.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
      if (visited[nx][ny]) continue;

      visited[nx][ny] = true;
      if (board[nx][ny] == 'X') {
        tq1.push({nx, ny});
      } else if (board[nx][ny] == '.') {
        q1.push({nx, ny});
      }
      if (nx == X2 && ny == Y2) {
        isFinished = true;
        break;
      }
    }
  }
}

void bfs2() {
  while (!q2.empty()) {
    pair<int, int> cur = q2.front();
    q2.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
      if (board[nx][ny] != 'X') continue;
      board[nx][ny] = '.';
      tq2.push({nx, ny});
    }
  }
}

void func() {
  while (!isFinished) {
    bfs1();
    if (isFinished) break;
    bfs2();
    q1 = tq1;
    q2 = tq2;
    tq1 = queue<pair<int, int>>();
    tq2 = queue<pair<int, int>>();
    ans++;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    cin >> s;
    for (int j = 0; j < C; j++) {
      board[i][j] = s[j];
      if (board[i][j] == 'L') {
        if (idx == 0) {
          X1 = i;
          Y1 = j;
          idx++;
        } else {
          X2 = i;
          Y2 = j;
        }
        board[i][j] = '.';
        q2.push({i, j});
      } else if (board[i][j] != 'X') {
        q2.push({i, j});
      }
    }
  }

  visited[X1][Y1] = true;
  q1.push({X1, Y1});
  func();
  cout << ans;

  return 0;
}