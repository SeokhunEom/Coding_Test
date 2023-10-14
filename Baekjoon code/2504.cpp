#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0, temp = 1;
  string s;
  stack<char> arr;
  cin >> s;
  int len = s.length();
  for(int i = 0; i < len; i++) {
    if(s[i] == '(') {
      arr.push('(');
      temp *= 2;
    }
    else if(s[i] == '[') {
      arr.push('[');
      temp *= 3;
    }
    else if(s[i] == ')') {
      if(arr.empty() || arr.top() != '(') {
        ans = 0;
        break;
      }
      if(s[i - 1] == '(')
        ans += temp;
      arr.pop();
      temp /= 2;
    }
    else if(s[i] == ']') {
      if(arr.empty() || arr.top() != '[') {
        ans = 0;
        break;
      }
      if(s[i - 1] == '[')
        ans += temp;
      arr.pop();
      temp /= 3;    
    }
  }
  if(!arr.empty())
    ans = 0;
  cout << ans;

  return 0;
}