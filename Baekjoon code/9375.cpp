#include <bits/stdc++.h>

using namespace std;

int T, n;
string s1, s2;
map<string, int> m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s1 >> s2;
      m[s2]++;
    }

    int ans = 1;
    for (map<string, int>::iterator i = m.begin(); i != m.end(); i++) {
      ans *= i->second + 1;
    }
    cout << ans - 1 << '\n';
    m.clear();
  }

  return 0;
}
