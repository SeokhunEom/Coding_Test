#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
int graph[101][101];
int dist[101][101];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (graph[a][b] == 0)
      graph[a][b] = c;
    else
      graph[a][b] = min(graph[a][b], c);
  }

  for (int i = 1; i <= n; i++) fill(dist[i] + 1, dist[i] + n + 1, INT_MAX);
  for (int i = 1; i <= n; i++) dist[i][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (graph[i][j] != 0) dist[i][j] = graph[i][j];
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] == INT_MAX)
        cout << 0 << ' ';
      else
        cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
