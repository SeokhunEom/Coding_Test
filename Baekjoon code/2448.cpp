#include <bits/stdc++.h>
using namespace std;

int N;
char star[3073][6145];

void init(void);
void rec(int a, int b, int n);
void printStar(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  init();
  rec(0, N - 1, N);
  printStar();

  return 0;
}

void init(void) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2 * N + 1; j++) {
      star[i][j] = ' ';
    }
  }
}

void rec(int a, int b, int n) {
  if (n == 3) {
    star[a][b] = '*';
    star[a + 1][b - 1] = '*';
    star[a + 1][b + 1] = '*';
    star[a + 2][b - 2] = '*';
    star[a + 2][b - 1] = '*';
    star[a + 2][b] = '*';
    star[a + 2][b + 1] = '*';
    star[a + 2][b + 2] = '*';
    return;
  }
  rec(a, b, n / 2);
  rec(a + n / 2, b - n / 2, n / 2);
  rec(a + n / 2, b + n / 2, n / 2);
}

void printStar(void) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2 * N + 1; j++) {
      cout << star[i][j];
    }
    cout << "\n";
  }
}