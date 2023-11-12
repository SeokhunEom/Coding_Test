#include <bits/stdc++.h>
using namespace std;

int N, K;
int dist[100001];
queue<int> q;

void bfs(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  fill(dist, dist + 100001, -1);
  bfs();

  cout << dist[K];

  return 0;
}

void bfs(void) {
  if (N == 0) {
    q.push(0);
    dist[0] = 0;
  } else {
    for (int i = N; i <= 100000; i *= 2) {
      q.push(i);
      dist[i] = 0;
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    int next[2] = {cur - 1, cur + 1};
    for (int i = 0; i < 2; i++) {
      if (next[i] < 0 || next[i] > 100000) continue;
      if (dist[next[i]] != -1 && dist[next[i]] <= dist[cur] + 1) continue;
      if (next[i] == 0) {
        q.push(0);
        dist[0] = dist[cur] + 1;
      } else {
        for (int j = next[i]; j <= 100000; j *= 2) {
          if (j < 0 || j > 100000) continue;
          if (dist[j] != -1 && dist[j] <= dist[cur] + 1) continue;
          q.push(j);
          dist[j] = dist[cur] + 1;
        }
      }
    }
  }
}