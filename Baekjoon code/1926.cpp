#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, maxsize = 0, num = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  queue<pair<int, int> > q;
  cin >> n >> m;
  int pic[n][m];
  int vis[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> pic[i][j];
      vis[i][j] = 0;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(pic[i][j] == 0 || vis[i][j])
        continue;
      num++;
      vis[i][j] = 1;
      q.push({i, j});
      int size = 0;
      while(!q.empty()) {
        size++;
        pair<int, int> cur = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
          int x = cur.first + dx[k];
          int y = cur.second + dy[k];
          if(x < 0 || x >= n || y < 0 || y >= m)
            continue;
          if(vis[x][y] || pic[x][y] != 1)
            continue;
          vis[x][y] = 1;
          q.push({x, y});
        }
      }
      maxsize = max(maxsize, size);
    }
  }
  cout << num << "\n" << maxsize;

  return 0;
}