#include <bits/stdc++.h>
using namespace std;

#define MAX 100000001

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, count = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    stack <char> arr;
    cin >> s;
    int len = s.length();
    for(int j = 0; j < len; j++) {
      if(s[j] == 'A') {
        if(!arr.empty() && arr.top() == 'A')
          arr.pop();
        else
          arr.push('A');
      }
      else if(s[j] == 'B') {
        if(!arr.empty() && arr.top() == 'B')
          arr.pop();
        else
          arr.push('B');
      }
    }
    if(arr.empty())
      count++;
  }
  cout << count;

  return 0;
}