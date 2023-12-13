#include <bits/stdc++.h>
using namespace std;

int ans;
char arr[5][5];
int princess[7];
bool vis[25];
bool check[5][5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string temp;

void func(int cnt, int idx);
bool isConnect(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
    cin >> temp;
    for (int j = 0; j < 5; j++) {
      arr[i][j] = temp[j];
    }
  }
  func(0, 0);
  cout << ans;

  return 0;
}

void func(int cnt, int idx) {
  if (cnt == 7) {
    if (!isConnect()) return;
    int s = 0;
    for (int i = 0; i < 7; i++) {
      if (arr[princess[i] / 5][princess[i] % 5] == 'S') s++;
    }
    if (s >= 4) ans++;
    return;
  }
  for (int i = idx; i < 25; i++) {
    if (vis[i]) continue;
    vis[i] = true;
    princess[cnt] = i;
    func(cnt + 1, i + 1);
    vis[i] = false;
  }
}

bool isConnect(void) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      check[i][j] = false;
    }
  }
  for (int i = 1; i < 7; i++) {
    check[princess[i] / 5][princess[i] % 5] = true;
  }

  queue<pair<int, int>> q;
  q.push({princess[0] / 5, princess[0] % 5});
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    int x = cur.first;
    int y = cur.second;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
      if (!check[nx][ny]) continue;
      check[nx][ny] = false;
      q.push({nx, ny});
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (check[i][j]) return false;
    }
  }
  return true;
}
