#include <bits/stdc++.h>
using namespace std;

int N, S, ans = 0;
int arr[21];

void func(int idx, int sum, int size);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  func(0, 0, 0);
  cout << ans;

  return 0;
}

void func(int idx, int sum, int size) {
  if (idx == N) {
    if (sum == S && size > 0) ans++;
    return;
  }
  func(idx + 1, sum + arr[idx], size + 1);
  func(idx + 1, sum, size);
}
