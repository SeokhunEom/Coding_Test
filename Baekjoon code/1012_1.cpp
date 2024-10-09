#include <iostream>
#include <queue>
using namespace std;

int T, M, N, K, X, Y, ans;
int board[51][51];
int visited[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    for (int i = 0; i < 51; i++) {
      for (int j = 0; j < 51; j++) {
        board[i][j] = 0;
        visited[i][j] = 0;
      }
    }

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
      cin >> X >> Y;
      board[X][Y] = 1;
    }

    ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (visited[i][j] == 1 || board[i][j] == 0) continue;
        ans++;
        q.push({i, j});
        visited[i][j] = 1;
        while (!q.empty()) {
          pair<int, int> cur = q.front();
          q.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (board[nx][ny] == 0 || visited[nx][ny] != 0) continue;
            q.push({nx, ny});
            visited[nx][ny] = 1;
          }
        }
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
