#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
string board[26];
int vis[26][26];
vector<int> ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> board[i];
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == '0' || vis[i][j] == 1) {
        continue;
      }
      queue<pair<int, int>> q;
      int size = 1;
      vis[i][j] = 1;
      q.push({i, j});
      while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
          int x = cur.first + dx[k];
          int y = cur.second + dy[k];
          if(x < 0 || x >= n || y < 0 || y >= n) {
            continue;
          }
          if(board[x][y] == '0' || vis[x][y] == 1) {
            continue;
          }
          q.push({x, y});
          vis[x][y] = 1;
          size++;
        }
      }
      ans.push_back(size);
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}