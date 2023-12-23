#include <bits/stdc++.h>
using namespace std;

int N, M, ans = 1000;
char board[10][10];
char temp[10][10];

void func(char board[10][10], int cnt);
int move(char board[10][10], int dir);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
  func(board, 0);
  cout << (ans == 1000 ? -1 : ans);

  return 0;
}

void func(char board[10][10], int cnt) {
  if (cnt == 10) return;
  char temp[10][10];
  for (int dir = 0; dir < 4; dir++) {
    memcpy(temp, board, sizeof(temp));
    int result = move(temp, dir);
    if (result == 1)
      ans = ans > cnt + 1 ? cnt + 1 : ans;
    else if (result == 0)
      func(temp, cnt + 1);
  }
}

int move(char board[10][10], int dir) {
  int result = 0;
  int rx, ry, bx, by;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 'R') {
        rx = i;
        ry = j;
        board[i][j] = '.';
      }
      if (board[i][j] == 'B') {
        bx = i;
        by = j;
        board[i][j] = '.';
      }
    }
  }

  if (dir == 0) {
    if (ry > by) {
      while (1) {
        if (board[rx][ry + 1] == '#') break;
        if (board[rx][ry + 1] == 'O') {
          result = 1;
          ry = -1;
          break;
        }
        ry++;
      }
      while (1) {
        if (board[bx][by + 1] == '#' || (bx == rx && by + 1 == ry)) break;
        if (board[bx][by + 1] == 'O') {
          result -= 10;
          break;
        }
        by++;
      }
    } else {
      while (1) {
        if (board[bx][by + 1] == '#') break;
        if (board[bx][by + 1] == 'O') {
          result = -10;
          by = -1;
          break;
        }
        by++;
      }
      while (1) {
        if (board[rx][ry + 1] == '#' || (bx == rx && ry + 1 == by)) break;
        if (board[rx][ry + 1] == 'O') {
          result += 1;
          break;
        }
        ry++;
      }
    }
  } else if (dir == 1) {
    if (rx > bx) {
      while (1) {
        if (board[rx + 1][ry] == '#') break;
        if (board[rx + 1][ry] == 'O') {
          result = 1;
          rx = -1;
          break;
        }
        rx++;
      }
      while (1) {
        if (board[bx + 1][by] == '#' || (bx + 1 == rx && by == ry)) break;
        if (board[bx + 1][by] == 'O') {
          result -= 10;
          break;
        }
        bx++;
      }
    } else {
      while (1) {
        if (board[bx + 1][by] == '#') break;
        if (board[bx + 1][by] == 'O') {
          result = -10;
          bx = -1;
          break;
        }
        bx++;
      }
      while (1) {
        if (board[rx + 1][ry] == '#' || (rx + 1 == bx && ry == by)) break;
        if (board[rx + 1][ry] == 'O') {
          result += 1;
          break;
        }
        rx++;
      }
    }
  } else if (dir == 2) {
    if (ry < by) {
      while (1) {
        if (board[rx][ry - 1] == '#') break;
        if (board[rx][ry - 1] == 'O') {
          result = 1;
          ry = -1;
          break;
        }
        ry--;
      }
      while (1) {
        if (board[bx][by - 1] == '#' || (bx == rx && by - 1 == ry)) break;
        if (board[bx][by - 1] == 'O') {
          result -= 10;
          break;
        }
        by--;
      }
    } else {
      while (1) {
        if (board[bx][by - 1] == '#') break;
        if (board[bx][by - 1] == 'O') {
          result = -10;
          by = -1;
          break;
        }
        by--;
      }
      while (1) {
        if (board[rx][ry - 1] == '#' || (bx == rx && ry - 1 == by)) break;
        if (board[rx][ry - 1] == 'O') {
          result += 1;
          break;
        }
        ry--;
      }
    }
  } else {
    if (rx < bx) {
      while (1) {
        if (board[rx - 1][ry] == '#') break;
        if (board[rx - 1][ry] == 'O') {
          result = 1;
          rx = -1;
          break;
        }
        rx--;
      }
      while (1) {
        if (board[bx - 1][by] == '#' || (bx - 1 == rx && by == ry)) break;
        if (board[bx - 1][by] == 'O') {
          result -= 10;
          break;
        }
        bx--;
      }
    } else {
      while (1) {
        if (board[bx - 1][by] == '#') break;
        if (board[bx - 1][by] == 'O') {
          result = -10;
          bx = -1;
          break;
        }
        bx--;
      }
      while (1) {
        if (board[rx - 1][ry] == '#' || (rx - 1 == bx && ry == by)) break;
        if (board[rx - 1][ry] == 'O') {
          result += 1;
          break;
        }
        rx--;
      }
    }
  }

  if (result == 0) {
    board[bx][by] = 'B';
    board[rx][ry] = 'R';
  }

  return result;
}