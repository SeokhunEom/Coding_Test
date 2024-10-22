#include <iostream>
#include <queue>
using namespace std;

int N, M, X1, Y1, X2, Y2, ans;
string s;
int board[301][301];
int visited[301][301];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool func() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      visited[i][j] = 0;
    }
  }

  queue<pair<int, int>> q;
  q.push({X1, Y1});
  visited[X1][Y1] = 1;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx == X2 && ny == Y2) return true;

      if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
      if (visited[nx][ny]) continue;
      visited[nx][ny] = 1;
      if (board[nx][ny] == 1) {
        board[nx][ny] = 0;
      } else {
        q.push({nx, ny});
      }
    }
  }

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  cin >> X1 >> Y1 >> X2 >> Y2;
  for (int i = 1; i <= N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      if (s[j] == '1') {
        board[i][j + 1] = 1;
      } else {
        board[i][j + 1] = 0;
      }
    }
  }
  if (X1 == X2 && Y1 == Y2) {
    cout << 0;
    return 0;
  }

  while (true) {
    ans++;
    bool flag = func();
    if (flag) break;
  }
  cout << ans;

  return 0;
}