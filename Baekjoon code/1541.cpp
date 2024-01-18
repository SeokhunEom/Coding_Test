#include <bits/stdc++.h>
using namespace std;

string s;
char last = '+';
int ans, n, t;
vector<int> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  for (char c : s) {
    if (c == '-' || c == '+') {
      if (last == '-') {
        v.push_back(n);
      } else {
        if (v.size() >= 1) {
          t = v.back();
          v.pop_back();
        } else {
          t = 0;
        }
        v.push_back(t + n);
      }
      n = 0;
      last = c;
    } else {
      n = n * 10 + (c - '0');
    }
  }
  if (last == '-') {
    v.push_back(n);
  } else {
    if (v.size() >= 1) {
      t = v.back();
      v.pop_back();
    } else {
      t = 0;
    }
    v.push_back(t + n);
  }

  int ans = v[0];
  for (int i = 1; i < v.size(); i++) ans -= v[i];
  cout << ans;

  return 0;
}
