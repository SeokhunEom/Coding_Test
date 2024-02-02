#include <bits/stdc++.h>
using namespace std;

int M, N, ans;
int arr[1000000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);

  int left = 1, right = arr[N - 1], mid, cnt;
  while (left <= right) {
    mid = (left + right) / 2;
    cnt = 0;
    for (int n : arr) cnt += n / mid;
    if (cnt >= M) {
      left = mid + 1;
      ans = mid;
    } else {
      right = mid - 1;
    }
  }
  cout << ans;

  return 0;
}
