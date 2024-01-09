#include <bits/stdc++.h>
using namespace std;

int N;
pair<long long, long long> dp[91];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  dp[1] = {0, 1};  // 1
  dp[2] = {1, 0};  // 10
  dp[3] = {1, 1};  // 100 101
  dp[4] = {2, 1};  // 1001 1000 1010
  for (int i = 2; i <= N; i++) {
    dp[i] = {dp[i - 1].first + dp[i - 1].second, dp[i - 1].first};
  }
  cout << dp[N].first + dp[N].second;

  return 0;
}
