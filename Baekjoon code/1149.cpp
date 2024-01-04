#include <bits/stdc++.h>
using namespace std;

int N, r, g, b;
tuple<int, int, int> arr[1000];
pair<int, int> dp[1000][3];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> r >> g >> b;
    arr[i] = {r, g, b};
  }

  dp[0][0] = {get<0>(arr[0]), 0};
  dp[0][1] = {get<1>(arr[0]), 1};
  dp[0][2] = {get<2>(arr[0]), 2};
  for (int i = 1; i < N; i++) {
    int prevR = dp[i - 1][0].first;
    int prevG = dp[i - 1][1].first;
    int prevB = dp[i - 1][2].first;
    dp[i][0] = {min(prevG, prevB) + get<0>(arr[i]), 0};
    dp[i][1] = {min(prevR, prevB) + get<1>(arr[i]), 1};
    dp[i][2] = {min(prevR, prevG) + get<2>(arr[i]), 2};
  }

  cout << min({dp[N - 1][0].first, dp[N - 1][1].first, dp[N - 1][2].first});

  return 0;
}
