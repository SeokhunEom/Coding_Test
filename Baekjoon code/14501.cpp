#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[16];
int dp[16];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;

  for (int i = 1; i <= N + 1; i++) {
    if (i + arr[i].first <= N + 1)
      dp[i + arr[i].first] = max(dp[i + arr[i].first], dp[i] + arr[i].second);
    dp[i + 1] = max(dp[i + 1], dp[i]);

    for (int i = 1; i <= N + 1; i++) {
      cout << dp[i] << ' ';
    }
    cout << '\n';
  }
  cout << dp[N + 1];

  return 0;
}
