#include <bits/stdc++.h>
using namespace std;

int N, M, V, a, b;
vector<int> graph[1001];
bool vis[1001];
stack<int> s;
queue<int> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> V;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  s.push(V);
  vis[V] = true;
  cout << V << ' ';
  while (!s.empty()) {
    int cur = s.top();
    s.pop();
    for (int i = 0; i < graph[cur].size(); i++) {
      int next = graph[cur][i];
      if (!vis[next]) {
        cout << next << ' ';
        s.push(cur);
        s.push(next);
        vis[next] = true;
        break;
      }
    }
  }
  cout << '\n';

  q.push(V);
  vis[V] = false;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << ' ';
    for (int i = 0; i < graph[cur].size(); i++) {
      int next = graph[cur][i];
      if (vis[next]) {
        q.push(next);
        vis[next] = false;
      }
    }
  }

  return 0;
}
