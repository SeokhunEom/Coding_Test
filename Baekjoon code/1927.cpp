#include <bits/stdc++.h>

using namespace std;

int N, a;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (a == 0) {
      if (pq.empty()) {
        cout << 0 << '\n';
      } else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      pq.push(a);
    }
  }

  return 0;
}
