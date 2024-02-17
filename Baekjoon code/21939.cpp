#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
string str;
map<int, int> m;
set<pair<int, int>> s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    m[a] = b;
    s.insert({b, a});
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> str;
    if (str[0] == 'r') {
      cin >> a;
      if (a == -1)
        cout << (*s.begin()).second << "\n";
      else
        cout << (*s.rbegin()).second << "\n";
    } else if (str[0] == 'a') {
      cin >> a >> b;
      m[a] = b;
      s.insert({b, a});
    } else {
      cin >> a;
      s.erase({m[a], a});
      m.erase(a);
    }
  }

  return 0;
}
