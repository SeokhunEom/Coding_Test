#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1) {
    int n;
    long long int res = 0;
    stack<pair<long long int, long long int> > s;
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i < n; i++) {
      int h, a = i;
      cin >> h;
      while(!s.empty() && s.top().first >= h) {
        res = max(res, (i - s.top().second) * s.top().first);
        a = s.top().second;
        s.pop();
      }
      s.push({h, a});
    }
    while(!s.empty()) {
      res = max(res, (n - s.top().second) * s.top().first);
      s.pop();
    }
    cout << res << "\n";
  }

  return 0;
}