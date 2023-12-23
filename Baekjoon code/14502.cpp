#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int board[8][8];
int temp[8][8];
int wall[3];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void func(int cnt, int idx);
int calc(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> board[i][j];
  }
  func(0, 0);
  cout << ans;

  return 0;
}

void func(int cnt, int idx) {
  if (cnt == 3) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        temp[i][j] = board[i][j];
      }
    }
    for (int i = 0; i < 3; i++) temp[wall[i] / M][wall[i] % M] = 1;
    int res = calc();
    ans = res > ans ? res : ans;
    return;
  }
  for (int i = idx; i < N * M; i++) {
    if (board[i / M][i % M] == 0) {
      wall[cnt] = i;
      func(cnt + 1, i + 1);
    }
  }
}

int calc(void) {
  int ret = 0;
  queue<pair<int, int>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 2) q.push({i, j});
    }
  }

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    int x = cur.first;
    int y = cur.second;
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (temp[nx][ny] == 0) {
        temp[nx][ny] = 2;
        q.push({nx, ny});
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (temp[i][j] == 0) ret++;
    }
  }

  return ret;
}