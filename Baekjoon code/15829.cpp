#include <bits/stdc++.h>
using namespace std;

int L;
string s;
unsigned long long ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L;
  cin >> s;

  for (int i = 0; i < L; i++) {
    unsigned long long t = s[i] - 'a' + 1;
    for (int j = 0; j < i; j++) {
      t *= 31;
      t %= 1234567891;
    }
    ans += t;
  }

  cout << ans % 1234567891;

  return 0;
}
