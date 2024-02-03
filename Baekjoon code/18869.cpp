#include <bits/stdc++.h>
using namespace std;

int M, N, t, ans;
pair<int, int> arr[100][10000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> t;
      arr[i][j] = {t, j};
    }
  }
  for (int i = 0; i < M; i++) sort(arr[i], arr[i] + N);

  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j < M; j++) {
      bool flag = true;

      for (int k = 0; k < N; k++) {
        if (arr[i][k].second != arr[j][k].second) {
          flag = false;
          break;
        }
        if (k < N - 1 && (arr[i][k].first < arr[i][k + 1].first !=
                          arr[j][k].first < arr[j][k + 1].first)) {
          flag = false;
          break;
        }
      }
      if (flag) ans++;
    }
  }
  cout << ans;

  return 0;
}
