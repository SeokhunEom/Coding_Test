#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0;; i++) {
    if (i == 0)
      N -= 1;
    else
      N -= 6 * i;
    if (N <= 0) {
      ans = i + 1;
      break;
    }
  }

  cout << ans;

  return 0;
}
