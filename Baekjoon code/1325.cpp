#include <iostream>
#include <queue>
using namespace std;

int N, M, A, B, max_cnt, cnt;
vector<int> adj[10001];
int visited[10001];
int ans[10001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    adj[B].push_back(A);
  }

  for (int i = 1; i <= N; i++) {
    cnt = 1;
    for (int i = 1; i <= N; i++) {
      visited[i] = 0;
    }
    queue<int> q;

    q.push(i);
    visited[i] = 1;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if (visited[next]) continue;
        visited[next] = 1;
        q.push(next);
        cnt++;
      }
    }

    max_cnt = max(max_cnt, cnt);
    ans[i] = cnt;
  }

  for (int i = 1; i <= N; i++) {
    if (ans[i] == max_cnt) {
      cout << i << ' ';
    }
  }

  return 0;
}