#include <iostream>
#include <queue>
using namespace std;

int N, M, ans1, ans2;
int board[101][101];
int visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int melt(void) {
  int ret = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visited[i][j] = 0;
      if (board[i][j] == 1) ret++;
    }
  }

  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = 1;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (visited[nx][ny] == 1) continue;
      if (board[nx][ny] == 1) {
        board[nx][ny] = 0;
        visited[nx][ny] = 1;
      } else {
        q.push({nx, ny});
        visited[nx][ny] = 1;
      }
    }
  }

  return ret;
}

bool check(void) {
  bool flag = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 1) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
  }

  return flag;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  while (true) {
    if (check()) {
      cout << ans1 << "\n" << ans2;
      break;
    }
    ans1++;
    ans2 = melt();
  }

  return 0;
}