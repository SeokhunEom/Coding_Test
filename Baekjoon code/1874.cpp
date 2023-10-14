#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a, temp = 1;
  stack<int> arr;
  string s;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    for(;temp <= a; temp++) {
      arr.push(temp);
      s.append("+");
    }
    if(arr.top() != a) {
      cout << "NO";
      return 0;
    }
    arr.pop();
    s.append("-");
  }
  int len = s.length();
  for(int i = 0; i < len; i++)
    cout << s[i] << "\n";
  
  return 0;
}