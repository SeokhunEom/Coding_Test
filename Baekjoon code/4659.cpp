#include <iostream>
using namespace std;

string s;

bool isMo(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> s;
    if (s == "end") break;

    bool flag1 = false, flag2 = true, flag3 = true;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        flag1 = true;

      if (i >= 2) {
        bool res1 = isMo(s[i - 2]);
        bool res2 = isMo(s[i - 1]);
        bool res3 = isMo(s[i]);

        if (res1 == res2 && res1 == res3) {
          flag2 = false;
          break;
        }
      }

      if (i >= 1 && s[i - 1] == s[i]) {
        if (s[i] != 'e' && s[i] != 'o') {
          flag3 = false;
          break;
        }
      }
    }

    if (flag1 == false || flag2 == false || flag3 == false) {
      cout << "<" << s << "> is not acceptable.\n";
    } else {
      cout << "<" << s << "> is acceptable.\n";
    }
  }

  return 0;
}