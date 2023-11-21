#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define BLUE 1

int N, white = 0, blue = 0;
int board[129][129];

int getColor(int a, int b, int n);
void rec(int a, int b, int n);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  rec(0, 0, N);
  cout << white << "\n" << blue;

  return 0;
}

int getColor(int a, int b, int n) {
  for (int i = a; i < a + n; i++) {
    for (int j = b; j < b + n; j++) {
      if (board[i][j] != board[a][b]) return -1;
    }
  }
  return board[a][b];
}

void rec(int a, int b, int n) {
  int color = getColor(a, b, n);
  if (color == WHITE) {
    white++;
    return;
  }
  if (color == BLUE) {
    blue++;
    return;
  }
  int half = n / 2;
  rec(a, b, half);
  rec(a, b + half, half);
  rec(a + half, b, half);
  rec(a + half, b + half, half);
}
