#include <bits/stdc++.h>
using namespace std;

int ans = 1000;
int board[5][5][5];
int temp[5][5][5];
int pathVis[5][5][5];
int arr[5][2];
bool arrVis[5];
int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void func(int cnt);
int path(void);
void position(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        cin >> board[i][j][k];
      }
    }
  }
  func(0);
  cout << (ans == 1000 ? -1 : ans);

  return 0;
}

void func(int cnt) {
  if (ans == 12) return;
  if (cnt == 5) {
    int dist = path();
    if (dist != -1) ans = ans < dist ? ans : dist;
    return;
  }
  for (int i = 0; i < 5; i++) {
    if (arrVis[i]) continue;
    arrVis[i] = true;
    arr[cnt][0] = i;
    for (int j = 0; j < 4; j++) {
      arr[cnt][1] = j;
      func(cnt + 1);
    }
    arrVis[i] = false;
  }
}

int path(void) {
  int dist = 0;
  position();
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        pathVis[i][j][k] = 0;
      }
    }
  }
  queue<tuple<int, int, int>> q;
  if (temp[0][0][0] == 0 || temp[4][4][4] == 0) return -1;
  q.push({0, 0, 0});
  pathVis[0][0][0] = 0;
  while (!q.empty()) {
    tuple<int, int, int> t = q.front();
    q.pop();
    int x = get<0>(t);
    int y = get<1>(t);
    int z = get<2>(t);
    if (x == 4 && y == 4 && z == 4) return pathVis[x][y][z];
    for (int dir = 0; dir < 6; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nz = z + dz[dir];
      if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
      if (temp[nx][ny][nz] == 0 || pathVis[nx][ny][nz] > 0) continue;
      q.push({nx, ny, nz});
      pathVis[nx][ny][nz] = pathVis[x][y][z] + 1;
    }
  }
  return -1;
}

void position(void) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (arr[i][1] == 0) {
          temp[i][j][k] = board[arr[i][0]][j][k];
        } else if (arr[i][1] == 1) {
          temp[i][k][4 - j] = board[arr[i][0]][j][k];
        } else if (arr[i][1] == 2) {
          temp[i][4 - j][4 - k] = board[arr[i][0]][j][k];
        } else {
          temp[i][4 - k][j] = board[arr[i][0]][j][k];
        }
      }
    }
  }
}