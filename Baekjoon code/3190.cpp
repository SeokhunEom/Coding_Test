#include <bits/stdc++.h>
using namespace std;

int N, K, x, y, L, ans, dir = 1;
pair<int, char> snake[101];
int board[101][101];
int dx[4] = {-1, 0, 1, 0};  // 상 우 하 좌
int dy[4] = {0, 1, 0, -1};

void func(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> x >> y;
    board[x - 1][y - 1] = 1;
  }
  cin >> L;
  for (int i = 0; i < L; i++) cin >> snake[i].first >> snake[i].second;
  x = 0;
  y = 0;
  board[0][0] = 2;
  func();
  cout << ans;

  return 0;
}

void func(void) {
  int idx = 0;
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (true) {
    ans++;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
    if (board[nx][ny] == 2) break;
    if (board[nx][ny] == 1) {
      board[nx][ny] = 2;
      q.push({nx, ny});
    } else {
      board[nx][ny] = 2;
      q.push({nx, ny});
      pair<int, int> t = q.front();
      q.pop();
      board[t.first][t.second] = 0;
    }
    x = nx;
    y = ny;

    if (snake[idx].first == ans) {
      if (snake[idx].second == 'L')
        dir = (dir + 3) % 4;
      else
        dir = (dir + 1) % 4;
      idx++;
    }
  }
}