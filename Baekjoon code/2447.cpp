#include <bits/stdc++.h>
using namespace std;

int N;
char star[6561][6561];

void init(void);
void rec(int a, int b, int n);
void printStar(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  init();
  rec(0, 0, N);
  printStar();

  return 0;
}

void init(void) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      star[i][j] = ' ';
    }
  }
}

void rec(int a, int b, int n) {
  if (n == 3) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == 1 && j == 1) continue;
        star[a + i][b + j] = '*';
      }
    }
    return;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) continue;
      rec(a + i * (n / 3), b + j * (n / 3), n / 3);
    }
  }
}

void printStar(void) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << star[i][j];
    }
    cout << "\n";
  }
}