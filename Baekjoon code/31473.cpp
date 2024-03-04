#include <bits/stdc++.h>
using namespace std;

int N, a, sum1, sum2, t;

int gcd(int a, int b);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    sum1 += a;
  }
  for (int i = 0; i < N; i++) {
    cin >> a;
    sum2 += a;
  }

  if (sum1 > sum2)
    t = gcd(sum1, sum2);
  else
    t = gcd(sum2, sum1);

  cout << sum2 / t << ' ' << sum1 / t;

  return 0;
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}