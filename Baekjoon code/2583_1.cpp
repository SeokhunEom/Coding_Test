#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int M, N, K, X1, X2, Y1, Y2, cnt;
int board[101][101];
int visited[101][101];
vector<int> area;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N >> K;
  for (int k = 0; k < K; k++) {
    cin >> X1 >> Y1 >> X2 >> Y2;
    for (int i = X1; i < X2; i++) {
      for (int j = Y1; j < Y2; j++) {
        board[j][i] = 1;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 1 || visited[i][j] == 1) continue;
      cnt = 0;
      queue<pair<int, int>> q;
      q.push({i, j});
      visited[i][j] = 1;
      while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        cnt++;
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];
          if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
          if (board[nx][ny] == 1 || visited[nx][ny] == 1) continue;
          q.push({nx, ny});
          visited[nx][ny] = 1;
        }
      }
      area.push_back(cnt);
    }
  }

  cout << area.size() << "\n";
  sort(area.begin(), area.end());
  for (int a : area) {
    cout << a << " ";
  }

  return 0;
}