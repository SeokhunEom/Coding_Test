#include <bits/stdc++.h>
using namespace std;

string s;

int calcLen(string str) {
  int strLen = str.size();
  int ans = 0, open = 0, close = 0;
  char t;
  string temp = "";

  if (str[0] == '(') {
    str = str.substr(1, strLen - 2);
    strLen -= 2;
  }

  for (int i = 0; i < strLen; i++) {
    if (str[i] == '(') {
      open++;
      if (open == 1) {
        t = str[i - 1];
      }
      temp += str[i];
    } else if (str[i] == ')') {
      close++;
      temp += str[i];
      if (open == close) {
        ans += calcLen(temp) * (t - '0');
        temp = "";
        open = 0;
        close = 0;
      }
    } else {
      if (open > close) {
        temp += str[i];
      } else {
        if (i < strLen - 1 && str[i + 1] == '(')
          continue;
        else
          ans++;
      }
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  cout << calcLen(s);

  return 0;
}
