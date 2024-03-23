#include <bits/stdc++.h>

using namespace std;

string s1, s2, tmp, ans;
int len1, len2, carry, x, y, digit;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s1 >> s2;

  len1 = s1.length();
  len2 = s2.length();

  if (len2 > len1) {
    swap(s1, s2);
    swap(len1, len2);
  }

  if (len1 != len2) {
    for (int i = 0; i < (len1 - len2); i++) tmp += "0";
  }
  s2 = tmp + s2;

  for (int i = len1 - 1; i >= 0; i--) {
    x = s1[i] - '0';
    y = s2[i] - '0';
    digit = x + y;
    if (carry == 1) {
      digit++;
      carry = 0;
    }
    if (digit > 9) carry = 1;
    ans += digit % 10 + '0';
  }
  if (carry == 1) ans += "1";

  for (int i = ans.length() - 1; i >= 0; i--) cout << ans[i];

  return 0;
}
