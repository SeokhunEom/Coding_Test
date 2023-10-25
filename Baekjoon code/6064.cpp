#include <bits/stdc++.h>
using namespace std;

int getGcd(int m, int n);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, m, n, x, y, year, maxYear;

  cin >> t;
  for (int i = 0; i < t; i++) {
    year = -1;
    cin >> m >> n >> x >> y;

    maxYear = m > n ? m * n / getGcd(m, n) : m * n / getGcd(n, m);
    for (int i = x; i <= maxYear; i += m) {
      if (i % n == y || (i % n == 0 && y == n)) {
        year = i;
        break;
      }
    }
    cout << year << "\n";
  }

  return 0;
}

int getGcd(int m, int n) {
  if (m % n == 0) {
    return n;
  }
  return getGcd(n, m % n);
}
