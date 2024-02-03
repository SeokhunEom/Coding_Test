#include <bits/stdc++.h>
using namespace std;

int n;
string s1, s2;
unordered_map<string, bool> m;
vector<string> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;
    if (s2 == "enter")
      m[s1] = true;
    else
      m[s1] = false;
  }
  for (auto it = m.begin(); it != m.end(); it++) {
    if (it->second) v.push_back(it->first);
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << '\n';

  return 0;
}
