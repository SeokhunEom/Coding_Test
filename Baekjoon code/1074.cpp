#include <bits/stdc++.h>
using namespace std;

int N, r, c;

int rec(int n, int a, int b);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> r >> c;
  cout << rec(N, r, c);

  return 0;
}

int rec(int n, int a, int b) {
  if (n == 1) {
    if (a == 0 && b == 0) return 0;
    if (a == 0 && b == 1) return 1;
    if (a == 1 && b == 0) return 2;
    return 3;
  }
  int half = 1 << (n - 1);
  if (a < half && b < half) return rec(n - 1, a, b);
  if (a < half && b >= half) return half * half + rec(n - 1, a, b - half);
  if (a >= half && b < half) return 2 * half * half + rec(n - 1, a - half, b);
  return 3 * half * half + rec(n - 1, a - half, b - half);
}
