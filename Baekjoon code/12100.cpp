#include <bits/stdc++.h>
using namespace std;

int N, step = 0, ans = 0;
int board[21][21];
int temp[21][21];
bool check[21][21];
int arr[5];

void func(int step);
void move(int dir);
void findMax(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      temp[i][j] = board[i][j];
    }
  }
  func(0);
  cout << ans;

  return 0;
}

void func(int step) {
  if (step == 5) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        board[i][j] = temp[i][j];
      }
    }
    for (int i = 0; i < 5; i++) {
      move(arr[i]);
    }
    findMax();
    return;
  }
  for (int i = 0; i < 4; i++) {
    arr[step] = i;
    func(step + 1);
  }
}

void move(int dir) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      check[i][j] = false;
    }
  }

  switch (dir) {
    case 0:
      for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
          if (board[i][j] == 0) continue;
          for (int k = j + 1; k < N; k++) {
            if (board[i][k] == 0) {
              board[i][k] = board[i][k - 1];
              board[i][k - 1] = 0;
            } else if (board[i][k] == board[i][k - 1] && !check[i][k]) {
              board[i][k] *= 2;
              board[i][k - 1] = 0;
              check[i][k] = true;
              break;
            } else {
              break;
            }
          }
        }
      }
      break;
    case 1:
      for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
          if (board[i][j] == 0) continue;
          for (int k = i + 1; k < N; k++) {
            if (board[k][j] == 0) {
              board[k][j] = board[k - 1][j];
              board[k - 1][j] = 0;
            } else if (board[k][j] == board[k - 1][j] && !check[k][j]) {
              board[k][j] *= 2;
              board[k - 1][j] = 0;
              check[k][j] = true;
              break;
            } else {
              break;
            }
          }
        }
      }
      break;
    case 2:
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (board[i][j] == 0) continue;
          for (int k = j - 1; k >= 0; k--) {
            if (board[i][k] == 0) {
              board[i][k] = board[i][k + 1];
              board[i][k + 1] = 0;
            } else if (board[i][k] == board[i][k + 1] && !check[i][k]) {
              board[i][k] *= 2;
              board[i][k + 1] = 0;
              check[i][k] = true;
              break;
            } else {
              break;
            }
          }
        }
      }
      break;
    case 3:
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (board[i][j] == 0) continue;
          for (int k = i - 1; k >= 0; k--) {
            if (board[k][j] == 0) {
              board[k][j] = board[k + 1][j];
              board[k + 1][j] = 0;
            } else if (board[k][j] == board[k + 1][j] && !check[k][j]) {
              board[k][j] *= 2;
              board[k + 1][j] = 0;
              check[k][j] = true;
              break;
            } else {
              break;
            }
          }
        }
      }
      break;
  }
}

void findMax() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (ans < board[i][j]) {
        ans = board[i][j];
      }
    }
  }
}