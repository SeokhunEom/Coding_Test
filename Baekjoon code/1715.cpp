#include <bits/stdc++.h>
using namespace std;

int N, n, a, b, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> n;
    pq.push(n);
  }
  while (!pq.empty()) {
    a = pq.top();
    pq.pop();
    if (pq.empty()) break;
    b = pq.top();
    pq.pop();
    ans += (a + b);
    pq.push(a + b);
  }

  cout << ans;

  return 0;
}
