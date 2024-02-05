#include <bits/stdc++.h>
using namespace std;

int N, M, t;
string s;
map<string, int> m1;
map<int, string> m2;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s;
    m1[s] = i + 1;
    m2[i + 1] = s;
  }
  for (int i = 0; i < M; i++) {
    cin >> s;
    if (s[0] >= '0' && s[0] <= '9') {
      t = stoi(s);
      cout << m2[t] << '\n';
    } else {
      cout << m1[s] << '\n';
    }
  }

  return 0;
}
