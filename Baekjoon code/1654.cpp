#include <bits/stdc++.h>
using namespace std;

int K, N, t, res;
long long arr[10000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K >> N;
  for (int i = 0; i < K; i++) cin >> arr[i];
  sort(arr, arr + K);

  long long first = 1, last = arr[K - 1], mid;
  while (first <= last) {
    t = 0;
    mid = (first + last) / 2;
    for (int i = 0; i < K; i++) t += arr[i] / mid;
    if (t >= N) {
      first = mid + 1;
      if (mid > res) res = mid;
    } else {
      last = mid - 1;
    }
  }
  cout << res;

  return 0;
}
