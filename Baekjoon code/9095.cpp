#include <bits/stdc++.h>
using namespace std;

int T, n;
int ans[12] = {0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    cout << ans[n] << "\n";
  }

  return 0;
}
