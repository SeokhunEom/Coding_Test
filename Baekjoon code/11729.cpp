#include <bits/stdc++.h>
using namespace std;

int N, ans = 1;

void hanoi(int a, int b, int n);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    ans *= 2;
  }
  ans -= 1;
  cout << ans << "\n";
  hanoi(1, 3, N);

  return 0;
}

void hanoi(int a, int b, int n) {
  if (n == 1) {
    cout << a << " " << b << "\n";
    return;
  }
  hanoi(a, 6 - a - b, n - 1);
  cout << a << " " << b << "\n";
  hanoi(6 - a - b, b, n - 1);
}