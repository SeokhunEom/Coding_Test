#include <iostream>
using namespace std;

int R, C, ans;
string s;
char board[21][21];
int visited[26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int cx, int cy, int dist) {
  ans = max(ans, dist);
  visited[board[cy][cx] - 'A'] = 1;
  for (int dir = 0; dir < 4; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
    if (visited[board[ny][nx] - 'A'] == 0) {
      dfs(nx, ny, dist + 1);
    }
  }
  visited[board[cy][cx] - 'A'] = 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    cin >> s;
    for (int j = 0; j < C; j++) {
      board[i][j] = s[j];
    }
  }

  dfs(0, 0, 1);
  cout << ans;

  return 0;
}