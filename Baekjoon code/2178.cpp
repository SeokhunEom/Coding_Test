#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  queue<pair<int, int> > q;
  cin >> n >> m;
  int maze[n][m], dist[n][m];
  string s;
  for(int i = 0; i < n; i++) {
    cin >> s;
    for(int j = 0; j < m; j++) {
      maze[i][j] = s[j] - 48;
      dist[i][j] = -1;
    }
  }
  q.push({0, 0});
  dist[0][0] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int x = cur.first + dx[i];
      int y = cur.second + dy[i];
      if(x < 0 || x >= n || y < 0 || y >= m)
        continue;
      if(dist[x][y] >= 1 || maze[x][y] != 1)
        continue;
      dist[x][y] = dist[cur.first][cur.second] + 1;
      q.push({x, y});
    }
  }
  cout << dist[n - 1][m - 1];

  return 0;
}