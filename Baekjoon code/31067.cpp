#include <bits/stdc++.h>
using namespace std;

int N, K, t, ans;
unsigned int track[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> track[i];

  for (int i = 1; i < N; i++) {
    if (track[i] <= track[i - 1]) {
      ans++;
      track[i] += K;
    }
  }
  for (int i = 1; i < N; i++) {
    if (track[i - 1] >= track[i]) ans = -1;
  }
  cout << ans;

  return 0;
}