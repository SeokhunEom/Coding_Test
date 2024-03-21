#include <bits/stdc++.h>

using namespace std;

int N, M, ans, cnt = -1;
string s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> s;
  for (char c : s) {
    if (c == 'I') {
      if (cnt % 2 == 1) {
        cnt++;
        if (cnt >= 2 * N) ans++;
      } else
        cnt = 0;
    } else {
      if (cnt % 2 == 0)
        cnt++;
      else
        cnt = -1;
    }
  }

  cout << ans;

  return 0;
}
