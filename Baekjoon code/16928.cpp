#include <bits/stdc++.h>

using namespace std;

int N, M, x, y;
int board[101];
int dist[101];
queue<int> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    board[x] = y;
  }
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    board[x] = y;
  }

  q.push(1);
  dist[1] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 1; i <= 6; i++) {
      int next = cur + i;
      if (next > 100) continue;
      if (board[next] != 0) next = board[next];
      if (dist[next] != 0) continue;
      dist[next] = dist[cur] + 1;
      q.push(next);
    }
  }

  cout << dist[100];

  return 0;
}
