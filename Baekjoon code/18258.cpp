#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  queue<int> q;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a;
    string str;
    cin >> str;
    if(str == "push") {
      cin >> a;
      q.push(a);
    }
    else if(str == "pop") {
      if(q.empty()) {
        cout << -1 << "\n";
        continue;
      }
      cout << q.front() << "\n";
      q.pop();
    }
    else if(str == "size") {
      cout << q.size() << "\n";
    }
    else if(str == "empty") {
      cout << q.empty() << "\n";
    }
    else if(str == "front") {
      if(q.empty()) {
        cout << -1 << "\n";
        continue;
      }
      cout << q.front() << "\n";
    }
    else if(str == "back"){
      if(q.empty()) {
        cout << -1 << "\n";
        continue;
      }
      cout << q.back() << "\n";
    }
  }

  return 0;
}