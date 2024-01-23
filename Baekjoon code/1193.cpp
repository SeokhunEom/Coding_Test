#include <bits/stdc++.h>
using namespace std;

int X, idx = 0, sum, a, b;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> X;
  while (sum < X) {
    idx++;
    sum += idx;
  }
  a = X - (sum - idx);
  b = idx + 1 - a;
  if (idx % 2 == 1)
    cout << b << '/' << a << '\n';
  else
    cout << a << '/' << b << '\n';

  return 0;
}
