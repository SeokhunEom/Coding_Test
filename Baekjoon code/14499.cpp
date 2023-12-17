#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int dice[7];
int N, M, x, y, K, dir;

void move(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> x >> y >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
  for (int i = 0; i < K; i++) {
    cin >> dir;
    move();
  }

  return 0;
}

void move(void) {
  int temp = dice[1];
  if (dir == 1) {
    if (y == M - 1) return;
    y++;
    dice[1] = dice[4];
    dice[4] = dice[6];
    dice[6] = dice[3];
    dice[3] = temp;
  } else if (dir == 2) {
    if (y == 0) return;
    y--;
    dice[1] = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = temp;
  } else if (dir == 3) {
    if (x == 0) return;
    x--;
    dice[1] = dice[5];
    dice[5] = dice[6];
    dice[6] = dice[2];
    dice[2] = temp;
  } else {
    if (x == N - 1) return;
    x++;
    dice[1] = dice[2];
    dice[2] = dice[6];
    dice[6] = dice[5];
    dice[5] = temp;
  }

  if (board[x][y] == 0) {
    board[x][y] = dice[6];
  } else {
    dice[6] = board[x][y];
    board[x][y] = 0;
  }
  cout << dice[1] << '\n';
}