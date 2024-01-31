#include <bits/stdc++.h>
using namespace std;

int N, M, ans = INT_MAX, t, idx;
int arr[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  for (int i = 0; i < N; i++) {
    idx = lower_bound(arr + i, arr + N, arr[i] + M) - arr;
    if (idx < N && ans > arr[idx] - arr[i]) ans = arr[idx] - arr[i];
  }
  cout << ans;

  return 0;
}
