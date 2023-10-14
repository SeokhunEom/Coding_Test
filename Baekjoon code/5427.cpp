#include <bits/stdc++.h>
using namespace std;

int n, w, h;
int board[1001][1001];
int fire[1001][1001];
int sang[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n--) {
    int t = 0;
    queue<pair<int, int> > qf;
    queue<pair<int, int> > qs;
    cin >> w >> h;
    for(int i = 0; i < h; i++) {
      fill(fire[i], fire[i] + w, 0);
      fill(sang[i], sang[i] + w, 0);
    }
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        char c;
        cin >> c;
        if(c == '#')
          board[i][j] = -1;
        else {
          if(c == '@') {
            qs.push({i, j});
            sang[i][j] = 1;
          } 
          else if(c == '*') {
            qf.push({i, j});
            fire[i][j] = 1;
          }
          board[i][j] = 0;
        }
      }
    }
    while(!qf.empty()) {
      auto cur = qf.front();
      qf.pop();
      for(int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if(nx < 0 || h <= nx || ny < 0 || w <= ny) 
          continue;
        if(board[nx][ny] == -1) 
          continue;
        if(fire[nx][ny]) 
          continue;
        fire[nx][ny] = fire[cur.first][cur.second] + 1;
        qf.push({nx, ny});
      }
    }
    while((!qs.empty()) && (!t)) {
      auto cur = qs.front();
      qs.pop();
      for(int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if(nx < 0 || h <= nx || ny < 0 || w <= ny) {
          cout << sang[cur.first][cur.second] << '\n';
          t = 1;
          break;
        }
        if(board[nx][ny] == -1) 
          continue;
        if(sang[nx][ny])
          continue;
        if(fire[nx][ny] != 0 && fire[nx][ny] <= sang[cur.first][cur.second] + 1)
          continue;
        sang[nx][ny] = sang[cur.first][cur.second] + 1;
        qs.push({nx, ny});
      }
    }
    if(!t) 
      cout << "IMPOSSIBLE" << '\n';
  }
  
  return 0;
}