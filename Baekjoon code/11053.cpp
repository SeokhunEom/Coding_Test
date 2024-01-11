#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
int arr[1000];
int dp[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
    }
  }

  for (int i = 0; i < N; i++) {
    if (ans < dp[i]) ans = dp[i];
  }
  cout << ans;

  return 0;
}
