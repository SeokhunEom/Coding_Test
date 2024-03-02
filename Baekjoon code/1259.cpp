#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    cin >> n;
    if (n == 0) break;
    string s = to_string(n);
    bool flag = true;
    for (int i = 0; i < s.size() / 2; i++) {
      if (s[i] != s[s.size() - i - 1]) {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "yes\n";
    else
      cout << "no\n";
  }

  return 0;
}
