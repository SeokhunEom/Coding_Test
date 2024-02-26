#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
vector<int> adj[32001];
int arr[32001];
queue<int> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    arr[b]++;
  }

  for (int i = 1; i <= N; i++) {
    if (arr[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << ' ';
    for (int next : adj[cur]) {
      arr[next]--;
      if (arr[next] == 0) q.push(next);
    }
  }

  return 0;
}
