#include <bits/stdc++.h>

using namespace std;

long long N, M, ans = 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  if (N >= M) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= N; i++) ans = (ans * i) % M;
  cout << ans;

  return 0;
}
