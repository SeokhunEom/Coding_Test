#include <bits/stdc++.h>

using namespace std;

double a, b, h, x;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> h;
  if (a > b) {
    double t = a;
    a = b;
    b = t;
  }
  x = a * h / (b - a);

  double t1 = b * b + (h + x) * (h + x);
  double t2 = a * a + x * x;

  if (a == b) {
    cout << -1;
    return 0;
  }
  cout << fixed << setprecision(6);
  cout << (t1 - t2) * M_PI;

  return 0;
}
