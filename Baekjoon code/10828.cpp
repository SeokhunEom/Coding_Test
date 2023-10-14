#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  stack<int> arr;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s;
    if(s == "push") {
      int a;
      cin >> a;
      arr.push(a);
    }
    else if (s == "pop") {
      if(!arr.empty()) {
        cout << arr.top() << endl;
        arr.pop();
      }
      else
        cout << -1 << endl;
    }
    else if (s == "size") {
      cout << arr.size() << endl;
    }
    else if (s == "empty") {
      if(arr.empty())
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
    else if (s == "top") {
      if(!arr.empty())
        cout << arr.top() << endl;
      else
        cout << -1 << endl;
    }
  }

  return 0;
}