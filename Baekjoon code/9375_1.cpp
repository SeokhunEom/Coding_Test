#include <iostream>
#include <map>
using namespace std;

int T, n;
string s1, s2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> n;

    map<string, int> m;
    for (int i = 0; i < n; i++) {
      cin >> s1 >> s2;
      if (m.find(s2) == m.end()) {
        m.insert({s2, 1});
      } else {
        m[s2]++;
      }
    }

    int ans = 1;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
      ans *= (iter->second + 1);
    }
    cout << ans - 1 << "\n";
  }

  return 0;
}