#include <bits/stdc++.h>
using namespace std;

int T, N;
pair<long long, long long> dp[41];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  dp[0] = {1, 0};
  dp[1] = {0, 1};
  for (int i = 2; i < 41; i++) {
    long long first = dp[i - 1].first + dp[i - 2].first;
    long long second = dp[i - 1].second + dp[i - 2].second;
    dp[i] = {first, second};
  }
  while (T--) {
    cin >> N;
    cout << dp[N].first << ' ' << dp[N].second << '\n';
  }

  return 0;
}
