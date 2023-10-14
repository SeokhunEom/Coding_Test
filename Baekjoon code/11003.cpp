#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, l;
  deque<pair<int, int> > dq;

  cin >> n >> l;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    while (!dq.empty() && dq.back().second >= a)
      dq.pop_back();
    dq.push_back({i, a});
    if (dq.front().first <= i - l) {
      dq.pop_front();
    }
    cout << dq.front().second << " ";
  }

  return 0;
}