#include <bits/stdc++.h>
using namespace std;

int T, N, M, n;
int arr[100];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; t++) {
    int ans = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      cin >> n;
      q.push({i, n});
      pq.push(n);
    }

    while (!q.empty()) {
      int idx = q.front().first;
      int val = q.front().second;
      q.pop();

      if (pq.top() == val) {
        pq.pop();
        ans++;
        if (idx == M) {
          cout << ans << '\n';
          break;
        }
      } else
        q.push({idx, val});
    }
  }

  return 0;
}
