#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
int arr[100001];
long long dp[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> arr[i];

  dp[0] = 0;
  for (int i = 1; i <= N; i++) dp[i] = dp[i - 1] + arr[i];

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    cout << dp[b] - dp[a - 1] << '\n';
  }

  return 0;
}
