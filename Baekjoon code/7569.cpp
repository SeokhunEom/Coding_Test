#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n, h, ans = 0;
  int tomato[101][101][101]; 
  int dist[101][101][101];
  int dx[6] = {0, 1, 0, -1, 0, 0};
  int dy[6] = {1, 0, -1, 0, 0, 0};
  int dz[6] = {0, 0, 0, 0, 1, -1};
  queue<tuple<int, int, int> > q;
  cin >> m >> n >> h;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        cin >> tomato[j][k][i];
        dist[j][k][i] = 0;
        if(tomato[j][k][i] == 1)
          q.push(make_tuple(j, k, i));
        if(tomato[j][k][i] == 0)
          dist[j][k][i] = -1;
      }
    }
  }
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int i = 0; i < 6; i++) {
      int x = get<0>(cur) + dx[i];
      int y = get<1>(cur) + dy[i];
      int z = get<2>(cur) + dz[i];
      if(x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h)
        continue;
      if(dist[x][y][z] >= 0)
        continue;
      dist[x][y][z] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
      q.push(make_tuple(x, y, z));
    }
  }
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        if(dist[j][k][i] == -1) {
          cout << -1;
          return 0;
        }
        ans = max(ans, dist[j][k][i]);
      }
    }
  }
  cout << ans;

  return 0;
}