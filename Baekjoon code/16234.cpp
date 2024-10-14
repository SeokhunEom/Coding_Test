#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, L, R, ans;
int board[50][50];
int visited[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L >> R;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  while (true) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        visited[i][j] = 0;
      }
    }

    bool flag = false;
    int idx = 1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (visited[i][j] != 0) continue;
        queue<pair<int, int>> q;
        vector<pair<int, int>> v;

        visited[i][j] = idx;
        q.push({i, j});
        v.push_back({i, j});
        while (!q.empty()) {
          pair<int, int> cur = q.front();
          q.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] != 0) continue;
            int diff = abs(board[cur.first][cur.second] - board[nx][ny]);
            if (diff >= L && diff <= R) {
              visited[nx][ny] = idx;
              q.push({nx, ny});
              v.push_back({nx, ny});
              flag = true;
            }
          }
        }

        if (v.size() > 1) {
          int sum = 0;
          for (pair<int, int> p : v) {
            sum += board[p.first][p.second];
          }
          sum /= v.size();
          for (pair<int, int> p : v) {
            board[p.first][p.second] = sum;
          }
        }
      }
    }

    if (!flag) break;
    ans++;
  }

  cout << ans;

  return 0;
}