#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c;
  queue<pair<int, int> > q1;
  queue<pair<int, int> > q2;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  cin >> r >> c;
  int dist1[r][c], dist2[r][c];
  string s[r];
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      dist1[i][j] = -1;
      dist2[i][j] = -1;
    }
  }
  for(int i = 0; i < r; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(s[i][j] == 'F') {
        q1.push({i, j});
        dist1[i][j] = 0;
      }
      if(s[i][j] == 'J') {
        q2.push({i, j});
        dist2[i][j] = 0;
      }
    }
  }
  while(!q1.empty()) {
    auto cur = q1.front();
    q1.pop();
    for(int i = 0; i < 4; i++) {
      int x = cur.first + dx[i];
      int y = cur.second + dy[i];
      if(x < 0 || x >= r || y < 0 || y >= c) 
        continue;
      if(dist1[x][y] >= 0 || s[x][y] == '#') 
        continue; 
      dist1[x][y] = dist1[cur.first][cur.second] + 1;
      q1.push({x, y});
    }
  }
  while(!q2.empty()) {
    auto cur = q2.front();
    q2.pop();
    for(int i = 0; i < 4; i++) {
      int x = cur.first + dx[i];
      int y = cur.second + dy[i];
      if(x < 0 || x >= r || y < 0 || y >= c) {
        cout << dist2[cur.first][cur.second] + 1;
        return 0;
      }
      if(dist2[x][y] >= 0 || s[x][y] == '#') 
        continue;
      if(dist1[x][y] != -1 && dist1[x][y] <= dist2[cur.first][cur.second] + 1) 
        continue;
      dist2[x][y] = dist2[cur.first][cur.second] + 1;
      q2.push({x,y});
    }
  }
  cout << "IMPOSSIBLE";

  return 0;
}