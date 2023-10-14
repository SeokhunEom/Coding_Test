#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int max_height = 0, max_count = 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
      if(max_height < board[i][j]) {
        max_height = board[i][j];
      }
    }
  }

  for(int rain = 1; rain <= max_height; rain++) {
    int count = 0;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        vis[i][j] = 0;
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(board[i][j] > rain && vis[i][j] == 0) {
          queue<pair<int, int>> q;
          count++;
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
              if(board[x][y] <= rain || vis[x][y] != 0) {
                continue;
              }
              q.push({x, y});
              vis[x][y] = 1;
            }
          }
        }
        if(count > max_count) {
          max_count = count;
        }
      }
    }
  }

  printf("%d\n", max_count);

  return 0;
}