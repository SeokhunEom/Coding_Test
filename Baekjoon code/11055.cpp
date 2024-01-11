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

  for (int i = 0; i < N; i++) {
    dp[i] = arr[i];
    for (int j = 0; j <= i; j++) {
      if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) dp[i] = dp[j] + arr[i];
    }
  }

  for (int a : dp) {
    if (ans < a) ans = a;
  }
  cout << ans;

  return 0;
}
