#include <bits/stdc++.h>
using namespace std;

#define MAX 100000001

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num = 0;
  string s;
  stack<char> arr;
  cin >> s;
  int len = s.length();
  for(int i = 0; i < len; i++) {
    if(s[i] == '(') {
      if(s[i + 1] == ')') {
        i++;
        num += arr.size();
      }
      else
        arr.push('(');
    }
    else if(s[i] == ')') {
      num++;
      arr.pop();
    }
  }
  cout << num;

  return 0;
}