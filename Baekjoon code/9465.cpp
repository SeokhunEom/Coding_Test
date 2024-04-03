#include <bits/stdc++.h>

using namespace std;

int T, n;
int sticker[2][100000];
int dp[2][100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> sticker[0][i];
    for (int i = 0; i < n; i++) cin >> sticker[1][i];

    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    dp[0][1] = sticker[0][1] + dp[1][0];
    dp[1][1] = sticker[1][1] + dp[0][0];

    for (int i = 2; i < n; i++) {
      dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
      dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
  }

  return 0;
}
