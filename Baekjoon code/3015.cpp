#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long int sum = 0;
  stack<pair<int, int> > s;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int h, a = 1;
    cin >> h;
    while(!s.empty() && s.top().first <= h) {
      sum += s.top().second;
      if(s.top().first == h)
        a += s.top().second;
      s.pop();
    }
    if(!s.empty())
      sum++;
    s.push({h, a});
  }
  cout << sum;

  return 0;
}