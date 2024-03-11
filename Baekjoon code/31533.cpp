#include <bits/stdc++.h>

using namespace std;

double a, m, n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> m >> n;
  double t1 = max(m, n / a);
  double t2 = max(n / a, m);
  double t3 = 2 * n / a;
  double t4 = 2 * m / a;
  cout << fixed << setprecision(6);
  cout << min({t1, t2, t3, t4});

  return 0;
}
