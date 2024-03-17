#include <bits/stdc++.h>

using namespace std;

int C, N, a, b, ans;
int arr[101][101];
bool vis[101];
queue<int> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> C >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    arr[a][b] = 1;
    arr[b][a] = 1;
  }

  q.push(1);
  vis[1] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 1; i <= C; i++) {
      if (arr[cur][i] && !vis[i]) {
        q.push(i);
        vis[i] = 1;
        ans++;
      }
    }
  }

  cout << ans;

  return 0;
}
