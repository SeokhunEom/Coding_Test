#include <bits/stdc++.h>
using namespace std;

int getGcd(int a, int b);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, gcd, lcm;
  cin >> a >> b;
  gcd = a > b ? getGcd(a, b) : getGcd(b, a);
  lcm = a * b / gcd;

  cout << gcd << '\n' << lcm;

  return 0;
}

int getGcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return getGcd(b, a % b);
}
