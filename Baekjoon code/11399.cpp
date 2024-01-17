#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  for (int i = N; i > 0; i--) ans += arr[N - i] * i;
  cout << ans;

  return 0;
}
