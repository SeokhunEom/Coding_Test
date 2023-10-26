#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long ans = 0;
  int n, digit = 0, temp;

  cin >> n;
  temp = n;
  while (1) {
    digit++;
    temp /= 10;
    if (temp == 0) {
      break;
    }
  }

  for (int i = 1; i < digit; i++) {
    ans += i * 9 * pow(10, i - 1);
  }
  ans += digit * (n - pow(10, digit - 1) + 1);

  cout << ans;

  return 0;
}