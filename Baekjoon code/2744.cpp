#include <bits/stdc++.h>
using namespace std;

string s, ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  for (char c : s) {
    if (c >= 'a' && c <= 'z')
      ans += c - 'a' + 'A';
    else
      ans += c - 'A' + 'a';
  }
  cout << ans;

  return 0;
}
