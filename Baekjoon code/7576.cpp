#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n, ans = 0;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  queue<pair<int, int> > q;
  cin >> m >> n;
  int tomato[n][m], dist[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> tomato[i][j];
      dist[i][j] = 0;
      if(tomato[i][j] == 1)
        q.push({i, j});
      if(tomato[i][j] == 0)
        dist[i][j] = -1;
    }
  }
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int x = cur.first + dx[i];
      int y = cur.second + dy[i];
      if(x < 0 || x >= n || y < 0 || y >= m)
        continue;
      if(dist[x][y] >= 0)
        continue;
      dist[x][y] = dist[cur.first][cur.second] + 1;
      q.push({x, y});
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(dist[i][j] == -1) {
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans;

  return 0;
}