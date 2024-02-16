#include <bits/stdc++.h>
using namespace std;

int T, K, n;
char c;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> K;
    multiset<int> ms;
    for (int k = 0; k < K; k++) {
      cin >> c >> n;
      if (c == 'I') {
        ms.insert(n);
      } else if (c == 'D' && n == 1) {
        if (!ms.empty()) {
          ms.erase(--ms.end());
        }
      } else {
        if (!ms.empty()) {
          ms.erase(ms.begin());
        }
      }
    }
    if (ms.empty())
      cout << "EMPTY" << '\n';
    else
      cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
  }

  return 0;
}
