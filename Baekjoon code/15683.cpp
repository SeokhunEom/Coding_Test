#include <bits/stdc++.h>
using namespace std;

int N, M, cctv, mini = 64;
int board[9][9];
int tmp[9][9];
int dir[9];

int func(void);
void up(int x, int y);
void down(int x, int y);
void right(int x, int y);
void left(int x, int y);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] != 0 && board[i][j] != 6) cctv++;
    }
  }

  int end = pow(4, cctv);
  for (int i = 0; i < end; i++) {
    for (int j = 0; j < cctv; j++) {
      dir[j] = (i >> (2 * j)) % 4;
    }
    int res = func();
    if (res < mini) {
      mini = res;
    }
  }
  cout << mini;

  return 0;
}

int func(void) {
  int res = 0, idx = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tmp[i][j] = board[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (tmp[i][j] == 1) {
        if (dir[idx] == 0) {
          up(i, j);
        } else if (dir[idx] == 1) {
          down(i, j);
        } else if (dir[idx] == 2) {
          right(i, j);
        } else if (dir[idx] == 3) {
          left(i, j);
        }
        idx++;
      } else if (tmp[i][j] == 2) {
        if (dir[idx] == 0) {
          up(i, j);
          down(i, j);
        } else if (dir[idx] == 1) {
          right(i, j);
          left(i, j);
        } else {
          return 64;
        }
        idx++;
      } else if (tmp[i][j] == 3) {
        if (dir[idx] == 0) {
          up(i, j);
          right(i, j);
        } else if (dir[idx] == 1) {
          up(i, j);
          left(i, j);
        } else if (dir[idx] == 2) {
          down(i, j);
          right(i, j);
        } else if (dir[idx] == 3) {
          down(i, j);
          left(i, j);
        }
        idx++;
      } else if (tmp[i][j] == 4) {
        if (dir[idx] == 0) {
          up(i, j);
          down(i, j);
          right(i, j);
        } else if (dir[idx] == 1) {
          up(i, j);
          down(i, j);
          left(i, j);
        } else if (dir[idx] == 2) {
          up(i, j);
          right(i, j);
          left(i, j);
        } else if (dir[idx] == 3) {
          down(i, j);
          right(i, j);
          left(i, j);
        }
        idx++;
      } else if (tmp[i][j] == 5) {
        if (dir[idx] == 0) {
          up(i, j);
          down(i, j);
          right(i, j);
          left(i, j);
        } else {
          return 64;
        }
        idx++;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (tmp[i][j] == 0) res++;
    }
  }

  return res;
}

void up(int x, int y) {
  int t = x;
  while (t < N && tmp[t][y] != 6) {
    if (tmp[t][y] == 0) tmp[t][y] = -1;
    t++;
  }
}

void down(int x, int y) {
  int t = x;
  while (t >= 0 && tmp[t][y] != 6) {
    if (tmp[t][y] == 0) tmp[t][y] = -1;
    t--;
  }
}

void right(int x, int y) {
  int t = y;
  while (t < M && tmp[x][t] != 6) {
    if (tmp[x][t] == 0) tmp[x][t] = -1;
    t++;
  }
}

void left(int x, int y) {
  int t = y;
  while (t >= 0 && tmp[x][t] != 6) {
    if (tmp[x][t] == 0) tmp[x][t] = -1;
    t--;
  }
}