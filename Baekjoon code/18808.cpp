#include <bits/stdc++.h>
using namespace std;

int N, M, K, R, C, ans = 0;
int board[41][41];
int sticker[11][11];

void func(void);
bool attach(int x, int y);
void rotate(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < K; i++) {
    cin >> R >> C;
    for (int j = 0; j < R; j++) {
      for (int k = 0; k < C; k++) {
        cin >> sticker[j][k];
      }
    }
    func();
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 1) {
        ans++;
      }
    }
  }
  cout << ans;

  return 0;
}

void func(void) {
  for (int dir = 0; dir < 4; dir++) {
    for (int x = 0; x <= N - R; x++) {
      for (int y = 0; y <= M - C; y++) {
        if (attach(x, y)) {
          return;
        }
      }
    }
    rotate();
  }
}

bool attach(int x, int y) {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (sticker[i][j] == 1 && board[x + i][y + j] == 1) {
        return false;
      }
    }
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (sticker[i][j] == 1) {
        board[x + i][y + j] = 1;
      }
    }
  }
  return true;
}

void rotate() {
  int temp[11][11];

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      temp[i][j] = sticker[i][j];
    }
  }
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < R; j++) {
      sticker[i][j] = temp[R - 1 - j][i];
    }
  }
  swap(R, C);
}