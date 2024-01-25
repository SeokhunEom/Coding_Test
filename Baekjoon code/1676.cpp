#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    int t = i;
    while (t % 5 == 0) {
      ans++;
      t /= 5;
    }
  }
  cout << ans;

  return 0;
}
