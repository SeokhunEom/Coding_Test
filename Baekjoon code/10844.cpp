#include <bits/stdc++.h>
using namespace std;

int N;
unsigned long long dp[101][11];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  dp[1][0] = 0;
  for (int i = 1; i <= 9; i++) {
    dp[1][i] = 1;
  }
  dp[1][10] = 9;

  for (int i = 2; i <= 100; i++) {
    dp[i][0] = dp[i - 1][1];
    for (int j = 1; j < 9; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
    }
    dp[i][9] = dp[i - 1][8];

    for (int j = 0; j <= 9; j++) {
      dp[i][10] = (dp[i][10] + dp[i][j]) % 1000000000;
    }
  }
  cout << dp[N][10];

  return 0;
}
