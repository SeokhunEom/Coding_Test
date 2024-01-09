#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N, greater<int>());
  for (int i = 0; i < N; i++) {
    int newAns = arr[i] * (i + 1);
    if (ans < newAns) ans = newAns;
  }
  cout << ans;

  return 0;
}
