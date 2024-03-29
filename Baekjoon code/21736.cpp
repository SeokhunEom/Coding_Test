#include <bits/stdc++.h>

using namespace std;

int N, M, cnt;
string board[601];
queue<pair<int, int>> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> board[i];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 'I') q.push({i, j});
    }
  }

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (board[nx][ny] == 'X') continue;

      if (board[nx][ny] == 'P') cnt++;
      board[nx][ny] = 'X';
      q.push({nx, ny});
    }
  }

  if (cnt == 0)
    cout << "TT";
  else
    cout << cnt;

  return 0;
}
