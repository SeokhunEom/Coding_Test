#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, l, x, y, xx, yy;
  int dist[301][301];
  int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  queue <pair<int, int>> q;

  cin >> t;
  while(t--) {
    cin >> l;
    cin >> x >> y;
    cin >> xx >> yy;
    for (int i = 0; i < l; i++) 
      fill(dist[i], dist[i] + l, -1);
    dist[x][y] = 0;
    q.push({x, y});
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int i = 0; i < 8; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if (nx < 0 || nx >= l || ny < 0 || ny >= l) 
          continue;
        if (dist[nx][ny] >= 0) 
          continue;
        dist[nx][ny] = dist[cur.first][cur.second] + 1;        
        q.push({nx, ny});
      }
    }
      cout << dist[xx][yy] << "\n";
  }

  return 0;
}