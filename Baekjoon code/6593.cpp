#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int l, r, c;
  char board[31][31][31];
  int dist[31][31][31];

  while(1) {
    cin >> l >> r >> c;
    if(l == 0 && r == 0 && c == 0) {
      break;
    }

    for(int i = 0; i < 31; i++) {
      for(int j = 0; j < 31; j++) {
        for(int k = 0; k < 31; k++) {
          board[i][j][k] = 0;
          dist[i][j][k] = -1;
        }
      }
    }

    int escape = 0;
    queue<tuple<int, int, int>> q;

    for(int i = 0; i < l; i++) {
      for(int j = 0; j < r; j++) {
        for(int k = 0; k < c; k++) {
          cin >> board[i][j][k];
          if(board[i][j][k] == 'S') {
            q.push({i, j, k});
            dist[i][j][k] = 0;
          }
        }
      }
    }

    while(!q.empty()) {
      if(escape) {
        break;
      }
      auto cur = q.front();
      q.pop();
      int curx, cury, curz;
      tie(curz, curx, cury) = cur;
      for(int i = 0; i < 6; i++) {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        int nz = curz + dz[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) {
          continue;
        }
        if(board[nz][nx][ny] == '#' || dist[nz][nx][ny] > 0) {
          continue;
        }
        dist[nz][nx][ny] = dist[curz][curx][cury] + 1;
        if(board[nz][nx][ny] == 'E') {
          cout << "Escaped in " << dist[nz][nx][ny] << " minute(s).\n";
          escape = 1;
          break;
        }
        q.push({nz, nx, ny});
      }
    }
    if(!escape) {
      cout << "Trapped!" << "\n";
    }
  }

  return 0;
}
