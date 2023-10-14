#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a[5], avg = 0, mid;

  cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
  sort(a, a+5);
  avg = (a[0] + a[1] + a[2] + a[3] + a[4]) / 5;
  mid = a[2];
  cout << avg << '\n' << mid;

  return 0;
}