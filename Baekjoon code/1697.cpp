#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  int dist[1000001];
  queue<int> q;
  cin >> n >> k;
  fill(dist, dist+1000000, -1);
  dist[n] = 0;
  q.push(n);
  while(dist[k] == -1) {
    int cur = q.front(), index = 0;
    q.pop();
    int next[3] = {cur - 1, cur + 1, 2 * cur};
    for(int i = 0; i < 3; i++) {
      if(next[i] < 0 || next[i] > 100000)
        continue;
      if(dist[next[i]] != -1)
        continue;
      dist[next[i]] = dist[cur] + 1;
      q.push(next[i]);
    }
  }
  cout << dist[k];

  return 0;
}