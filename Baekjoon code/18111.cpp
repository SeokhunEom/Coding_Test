#include <bits/stdc++.h>

using namespace std;

int N, B, M, maxHeight, minHeight = INT_MAX, minTime = INT_MAX, ansHeight;
int board[500][500];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> B;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> board[i][j];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] > maxHeight) maxHeight = board[i][j];
      if (board[i][j] < minHeight) minHeight = board[i][j];
    }
  }

  for (int i = maxHeight; i >= minHeight; i--) {
    int time = 0, block = B;
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (board[j][k] > i) {
          time += 2 * (board[j][k] - i);
          block += board[j][k] - i;
        } else if (board[j][k] < i) {
          time += i - board[j][k];
          block -= i - board[j][k];
        }
      }
    }
    if (block < 0) continue;
    if (time < minTime) {
      minTime = time;
      ansHeight = i;
    }
  }

  cout << minTime << " " << ansHeight;

  return 0;
}
