#include <bits/stdc++.h>
using namespace std;

#define MAX 100000001

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    int res = 1;
    string s;
    stack<char> arr;
    cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i++) {
      if(s[i] == '(') {
        arr.push('(');
      }
      else if(s[i] == ')') {
        if(arr.empty()) {
          res = 0;
          break;
        }
        arr.pop();
      }
    }
    if(!arr.empty())
      res = 0;
    if(res)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }

  return 0;
}