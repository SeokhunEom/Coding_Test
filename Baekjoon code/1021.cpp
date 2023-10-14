#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, ans = 0;
  deque<int> dq;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    dq.push_back(i);
  }
  for(int i = 0; i < m; i++) {
    int t, left = 0, right = 0;
    cin >> t;
    int ind = find(dq.begin(), dq.end(), t) - dq.begin();
    while(dq.front() != t){
      if(ind * 2 < dq.size()){
        dq.push_back(dq.front());
        dq.pop_front();
      }
      else {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      ans++;
    }
    dq.pop_front();
  }
  cout << ans;

  return 0;
}