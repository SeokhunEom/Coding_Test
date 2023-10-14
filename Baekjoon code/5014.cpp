#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d, ans;
int dist[1000001];
queue<int> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> f >> s >> g >> u >> d;
  for(int i = 0; i < 1000001; i++) {
    dist[i] = -1;
  }

  q.push(s);
  dist[s] = 0;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    ans++;
    int up = cur + u;
    if(up <= f && up > 0 && dist[up] == -1) {
      dist[up] = dist[cur] + 1;
      q.push(up);
    }
    int down = cur - d;
    if(down <= f && down > 0 && dist[down] == -1) {
      dist[down] = dist[cur] + 1;
      q.push(down);
    }
  }

  if(dist[g] == -1) {
    printf("use the stairs\n");
  }
  else {
    printf("%d\n", dist[g]);
  }

  return 0;
}