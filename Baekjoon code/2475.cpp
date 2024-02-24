#include <bits/stdc++.h>
using namespace std;

int a, sum;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
    cin >> a;
    sum += a * a;
  }
  cout << sum % 10;

  return 0;
}
