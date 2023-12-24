#include <bits/stdc++.h>
using namespace std;

long long n, a, b, c;

void func(int cnt);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  func(0);
  cout << a + b + c;

  return 0;
}

void func(int cnt) {
  if (cnt == n) return;
  if (cnt == 0) {
    a = -1;
    b = 1;
    c = 1;
    func(cnt + 1);
  } else {
    long long tempa = a;
    long long tempb = b;
    long long tempc = c;
    a = tempa - tempc;
    b = tempb + tempc;
    c = (2 * tempa) - (2 * tempb) + tempc;
    func(cnt + 1);
  }
}