#include <bits/stdc++.h>
using namespace std;

long long N, cnt, maxCnt, ans;
long long arr[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);

  for (int i = 0; i < N; i++) {
    if (i == 0 || arr[i] == arr[i - 1])
      cnt++;
    else {
      if (cnt > maxCnt) {
        maxCnt = cnt;
        ans = arr[i - 1];
      }
      cnt = 1;
    }
  }
  if (cnt > maxCnt) ans = arr[N - 1];

  cout << ans;

  return 0;
}
