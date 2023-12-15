#include <bits/stdc++.h>
using namespace std;

char board[12][6];
bool vis[12][6];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans;
bool flag = true;

void gravity(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 12; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 6; j++) {
      board[i][j] = s[j];
    }
  }
  while (flag) {
    flag = false;
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        vis[i][j] = board[i][j] == '.' ? true : false;
      }
    }

    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        if (vis[i][j]) continue;
        vector<pair<int, int>> v;
        queue<pair<int, int>> q;
        q.push({i, j});
        v.push_back({i, j});
        vis[i][j] = true;
        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (vis[nx][ny] || board[nx][ny] != board[x][y]) continue;
            q.push({nx, ny});
            v.push_back({nx, ny});
            vis[nx][ny] = true;
          }
        }
        if (v.size() >= 4) {
          flag = true;
          for (int k = 0; k < v.size(); k++) {
            board[v[k].first][v[k].second] = '.';
          }
        }
      }
    }
    gravity();
    if (flag) ans++;
  }
  cout << ans;

  return 0;
}

void gravity(void) {
  for (int i = 0; i < 6; i++) {
    for (int j = 11; j >= 0; j--) {
      if (board[j][i] == '.') {
        for (int k = j - 1; k >= 0; k--) {
          if (board[k][i] != '.') {
            board[j][i] = board[k][i];
            board[k][i] = '.';
            break;
          }
        }
      }
    }
  }
}