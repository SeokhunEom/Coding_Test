#include <iostream>
#include <queue>
using namespace std;

int N, max_height, ans, cnt;
int input[101][101];
int board[101][101];
int visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> input[i][j];
      max_height = max(max_height, input[i][j]);
    }
  }

  for (int height = 0; height <= max_height; height++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (input[i][j] <= height) {
          board[i][j] = 0;
        } else {
          board[i][j] = 1;
        }
        visited[i][j] = 0;
      }
    }

    cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == 0 || visited[i][j] == 1) continue;
        cnt++;
        q.push({i, j});
        visited[i][j] = 1;
        while (!q.empty()) {
          pair<int, int> cur = q.front();
          q.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] == 0 || visited[nx][ny] == 1) continue;
            q.push({nx, ny});
            visited[nx][ny] = 1;
          }
        }
      }
    }

    ans = max(ans, cnt);
  }

  cout << ans;

  return 0;
}