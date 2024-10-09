#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[101][101];
int visited[101][101];
queue<pair<int, int>> q;
string s;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      board[i][j] = s[j] - '0';
    }
  }

  q.push({0, 0});
  visited[0][0] = 1;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (board[nx][ny] == 0 || visited[nx][ny] != 0) continue;
      q.push({nx, ny});
      visited[nx][ny] = visited[cur.first][cur.second] + 1;
    }
  }
  cout << visited[N - 1][M - 1] << '\n';

  return 0;
}
