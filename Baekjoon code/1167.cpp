#include <bits/stdc++.h>

using namespace std;

int V, a, b, c, maxDist, maxNode;
vector<pair<int, int>> v[100001];
bool vis[100001];

void dfs(int idx, int dist) {
  if (vis[idx]) return;

  if (maxDist < dist) {
    maxDist = dist;
    maxNode = idx;
  }
  vis[idx] = true;

  for (int i = 0; i < v[idx].size(); i++) {
    int ni = v[idx][i].first;
    int nd = v[idx][i].second;
    dfs(ni, nd + dist);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V;
  for (int i = 0; i < V; i++) {
    cin >> a;
    while (1) {
      cin >> b;
      if (b == -1) break;
      cin >> c;
      v[a].push_back({b, c});
    }
  }

  dfs(1, 0);
  memset(vis, 0, sizeof(vis));
  maxDist = 0;
  dfs(maxNode, 0);
  cout << maxDist << '\n';

  return 0;
}
