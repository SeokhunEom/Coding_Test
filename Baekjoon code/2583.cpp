#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};
int board[101][101] = {0, };
int vis[101][101] = {0, };

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n, k, x1, x2, y1, y2, count = 0;
  vector<int> ans;

  cin >> m >> n >> k;
  for(int i = 0; i < k; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for(int j = y1; j < y2; j++) {
      for(int k = x1; k < x2; k++) {
        board[j][k] = 1;
      }
    }
  }

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      int width = 1;
      if(board[i][j] == 1 || vis[i][j] == 1) {
        continue;
      }
      queue<pair<int, int>> q;
      vis[i][j] = 1;
      q.push({i, j});
      count++;
      while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int a = 0; a < 4; a++) {
          int nx = cur.first + dx[a];
          int ny = cur.second + dy[a];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
          }
          if (board[nx][ny] == 1 || vis[nx][ny] == 1) {
            continue;
          }
          q.push({ nx, ny });
          vis[nx][ny] = 1;
          width++;
        }
      }
      ans.push_back(width);
    }
  }

  sort(ans.begin(), ans.end());
  cout << count << '\n';
  for(int i = 0; i < count; i++) {
    cout << ans[i] << " ";
  }

  return 0;
}