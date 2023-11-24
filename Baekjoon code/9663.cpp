#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
bool vis1[16], vis2[31], vis3[31];

void func(int cur);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  func(0);
  cout << ans;

  return 0;
}

void func(int cur) {
  if (cur == N) {
    ans++;
    return;
  }
  for (int i = 0; i < N; i++) {
    if (vis1[i] || vis2[i + cur] || vis3[cur - i + N - 1]) continue;
    vis1[i] = true;
    vis2[i + cur] = true;
    vis3[cur - i + N - 1] = true;
    func(cur + 1);
    vis1[i] = false;
    vis2[i + cur] = false;
    vis3[cur - i + N - 1] = false;
  }
}