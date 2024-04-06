#include <bits/stdc++.h>

using namespace std;

int N, M, X1, Y1, X2, Y2;
int arr[1025][1025];
int sum[1025][1025];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> arr[i][j];
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> X1 >> Y1 >> X2 >> Y2;
    cout << sum[X2][Y2] - sum[X1 - 1][Y2] - sum[X2][Y1 - 1] +
                sum[X1 - 1][Y1 - 1]
         << '\n';
  }

  return 0;
}
