#include <bits/stdc++.h>
using namespace std;

int n;
int arr[501][501];
int dp[501][501];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> arr[i][j];
    }
  }

  dp[0][0] = arr[0][0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int a = dp[i - 1][j] + arr[i][j];
      int b = j > 0 ? dp[i - 1][j - 1] + arr[i][j] : 0;
      dp[i][j] = a > b ? a : b;
    }
  }

  int max = dp[n - 1][0];
  for (int i = 1; i <= n; i++) {
    if (max < dp[n - 1][i]) max = dp[n - 1][i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << dp[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << max;

  return 0;
}
