#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, ans;
vector<int> adj[1001];
bool vis[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= N; i++) {
    if (vis[i]) continue;
    ans++;
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        q.push(nxt);
        vis[nxt] = true;
      }
    }
  }
  cout << ans;

  return 0;
}
