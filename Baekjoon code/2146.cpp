#include <bits/stdc++.h>
using namespace std;

int N, land = 1, ans = 10000;
int arr[101][101];
bool vis[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void rename(void);
int bfs(int num);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  rename();
  for (int i = 2; i < land; i++) {
    int dist = bfs(i);
    if (dist < ans) ans = dist;
  }

  cout << ans;

  return 0;
}

void rename(void) {
  bool flag = true;

  while (flag) {
    queue<pair<int, int>> q;
    flag = false;
    land++;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (arr[i][j] == 1) {
          q.push({i, j});
          vis[i][j] = true;
          arr[i][j] = land;
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) break;

    while (!q.empty()) {
      pair<int, int> cur = q.front();
      q.pop();

      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (arr[nx][ny] == 0 || vis[nx][ny] == true) continue;
        q.push({nx, ny});
        vis[nx][ny] = true;
        arr[nx][ny] = land;
      }
    }
  }
}

int bfs(int num) {
  int dist = 0;
  queue<pair<int, int>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      vis[i][j] = false;
      if (arr[i][j] == num) {
        q.push({i, j});
        vis[i][j] = true;
      }
    }
  }

  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      pair<int, int> cur = q.front();
      q.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (arr[nx][ny] != 0 && arr[nx][ny] != num) return dist;
        if (arr[nx][ny] == 0 && vis[nx][ny] == false) {
          vis[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }
    dist++;
  }

  return 0;
}