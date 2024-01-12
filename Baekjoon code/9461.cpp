#include <bits/stdc++.h>
using namespace std;

int T, a;
long long dp[101];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = dp[5] = 2;
  for (int i = 6; i <= 100; i++) {
    dp[i] = dp[i - 2] + dp[i - 3];
  }
  for (int i = 0; i < T; i++) {
    cin >> a;
    cout << dp[a] << '\n';
  }

  return 0;
}
