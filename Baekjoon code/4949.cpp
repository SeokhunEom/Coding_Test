#include <bits/stdc++.h>
using namespace std;

#define MAX 100000001

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1) {
    int b = 0;
    string s;
    stack <char> arr;
    getline(cin, s);
    if(s == ".") 
      break;
    int len = s.length();
    for(int i = 0; i < len; i++) {
      if(s[i] == '(')
        arr.push('(');
      else if(s[i] == ')') {
        if(arr.empty() || arr.top() != '(') {
          cout << "no" << "\n";
          b = 1;
          break;
        }
        arr.pop();
      }
      else if(s[i] == '[')
        arr.push('[');
      else if(s[i] == ']') {
        if(arr.empty() || arr.top() != '[') {
          cout << "no" << "\n";
          b = 1;
          break;
        }
        arr.pop();
      }
    }
    if(b == 0 && arr.empty())
      cout << "yes" << "\n";
    else if(b == 0)
      cout << "no" << "\n";
  }

  return 0;
}