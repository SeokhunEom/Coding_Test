#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, m, n, k;
  int field[51][51];
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  cin >> t;
  while(t--) {
    cin >> m >> n >> k;
    int ans = 0;
    for(int i = 0; i < 51; i++) {
      for(int j = 0; j < 51; j++)
        field[i][j] = 0;
    }    
    for(int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      field[a][b] = 1;
    }
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        queue<pair<int, int> > q;
        if(field[i][j]) {
          q.push({i, j});
          field[i][j] = 0;
          ans++;
          while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(int l = 0; l < 4; l++) {
              int x = cur.first + dx[l];
              int y = cur.second + dy[l];
              if(x < 0 || x > m || y < 0 || y > n)
                continue;
              if(field[x][y] == 0)
                continue;
              q.push({x, y});
              field[x][y] = 0;
            }
          }
        }
      }
    }
    cout << ans << "\n";
  }

  return 0;
}