#include <bits/stdc++.h>

using namespace std;

int N, M, a, b, ans, minVal = INT_MAX;
int arr[101][101];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    arr[a][b] = 1;
    arr[b][a] = 1;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (arr[i][j] == 0) arr[i][j] = INT_MAX;
    }
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j) continue;
        if (arr[i][k] == INT_MAX || arr[k][j] == INT_MAX) continue;
        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) sum += arr[i][j];
    if (minVal > sum) {
      minVal = sum;
      ans = i;
    }
  }

  cout << ans;

  return 0;
}
