#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, ans1 = 0, ans2 = 0;
  char temp;
  char arr[101][101];
  char arr2[101][101];
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  queue<pair<int, int> > q;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(arr[i][j] == 'R')
        arr2[i][j] = 'G';
      else
        arr2[i][j] = arr[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(arr[i][j] != 'Q') {
        temp = arr[i][j];
        q.push({i, j});
        ans1++;
      }
      while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
          int x = cur.first + dx[k];
          int y = cur.second + dy[k];
          if(x < 0 || x > n || y < 0 || y > n)
            continue;
          if(arr[x][y] != temp)
            continue;
          q.push({x, y});
          arr[x][y] = 'Q';
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(arr2[i][j] != 'Q') {
        temp = arr2[i][j];
        q.push({i, j});
        ans2++;
      }
      while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
          int x = cur.first + dx[k];
          int y = cur.second + dy[k];
          if(x < 0 || x > n || y < 0 || y > n)
            continue;
          if(arr2[x][y] != temp)
            continue;
          q.push({x, y});
          arr2[x][y] = 'Q';
        }
      }
    }
  }
  cout << ans1 << " " << ans2;

  return 0;
}