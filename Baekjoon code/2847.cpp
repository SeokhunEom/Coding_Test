#include <bits/stdc++.h>
using namespace std;

int N, t, ans;
int arr[100];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  int t = arr[N - 1];
  for (int i = N - 2; i >= 0; i--) {
    if (arr[i] >= t) {
      ans += arr[i] - t + 1;
      t = t - 1;
    } else {
      t = arr[i];
    }
  }
  cout << ans;

  return 0;
}
