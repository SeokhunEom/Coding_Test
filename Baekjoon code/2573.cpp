#include <bits/stdc++.h>
using namespace std;

#define ALLZERO 0
#define ONLYONE 1
#define MORE2 2

int N, M, year = 0;
int arr[301][301];
bool vis[301][301];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void melt(void);
int check(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  bool flag = true;
  while (flag) {
    melt();
    year++;
    int result = check();
    switch (result) {
      case ALLZERO:
        flag = false;
        year = 0;
        break;
      case ONLYONE:
        break;
      case MORE2:
        flag = false;
        break;
    }
  }

  cout << year;

  return 0;
}

void melt(void) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == 0) continue;
      for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (arr[nx][ny] != 0) continue;
        arr[i][j]--;
      }
      if (arr[i][j] <= 0) arr[i][j] = -1;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == -1) arr[i][j] = 0;
    }
  }
}

int check(void) {
  queue<pair<int, int>> q;
  int flag = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      vis[i][j] = false;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] != 0) {
        q.push({i, j});
        vis[i][j] = true;
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
  }
  if (flag == 0) return ALLZERO;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (arr[nx][ny] == 0 || vis[nx][ny] == true) continue;
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] != 0 && vis[i][j] == false) {
        return MORE2;
      }
    }
  }
  return ONLYONE;
}