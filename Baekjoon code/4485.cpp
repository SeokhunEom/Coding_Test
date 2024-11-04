#include <iostream>
#include <queue>
using namespace std;

int N, num = 0;
int arr[126][126];
int visited[126][126];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> N;
    if (N == 0) break;

    num++;
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> arr[i][j];
        visited[i][j] = -1;
      }
    }

    q.push({0, 0});
    visited[0][0] = arr[0][0];
    while (!q.empty()) {
      pair<int, int> cur = q.front();
      q.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (visited[nx][ny] == -1 ||
            visited[nx][ny] > visited[cur.first][cur.second] + arr[nx][ny]) {
          visited[nx][ny] = visited[cur.first][cur.second] + arr[nx][ny];
          q.push({nx, ny});
        }
      }
    }

    cout << "Problem " << num << ": " << visited[N - 1][N - 1] << "\n";
  }

  return 0;
}