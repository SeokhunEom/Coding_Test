#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long mem[1000001] = {
      0,
  };
  int t, n;

  for (int i = 1; i <= 1000000; i++) {
    for (int j = 1; i * j <= 1000000; j++) {
      mem[i * j] += i;
    }
    mem[i] += mem[i - 1];
  }

  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    cout << mem[n] << '\n';
  }

  return 0;
}