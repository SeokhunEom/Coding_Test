#include <bits/stdc++.h>
using namespace std;

int N, M;
string s1, s2;
map<string, string> m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s1 >> s2;
    m[s1] = s2;
  }
  for (int i = 0; i < M; i++) {
    cin >> s1;
    cout << m[s1] << "\n";
  }

  return 0;
}
