#include <bits/stdc++.h>
using namespace std;

int n, k;
int coin[100];
int dp[10001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> coin[i];
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = coin[i - 1]; j <= k; j++) dp[j] += dp[j - coin[i - 1]];
  }
  cout << dp[k];

  return 0;
}
