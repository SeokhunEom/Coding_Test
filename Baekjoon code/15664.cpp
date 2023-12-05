#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8];
int ans[8];
bool vis[8];

void func(int n, int idx);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + N);
  func(0, 0);

  return 0;
}

void func(int n, int idx) {
  if (n == M) {
    for (int i = 0; i < M; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }
  int prev = 0;
  for (int i = idx; i < N; i++) {
    if (vis[i] || arr[i] == prev) continue;
    vis[i] = true;
    ans[n] = arr[i];
    prev = ans[n];
    func(n + 1, i + 1);
    vis[i] = false;
  }
}