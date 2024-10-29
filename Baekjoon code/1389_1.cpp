#include <climits>
#include <iostream>
using namespace std;

int N, M, a, b, minn = INT_MAX, ans;
int graph[101][101];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (graph[i][j] == 0) {
        graph[i][j] = INT_MAX;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        if (j == k) continue;
        if (graph[j][i] == INT_MAX || graph[i][k] == INT_MAX) continue;
        graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      sum += graph[i][j];
    }
    if (minn > sum) {
      minn = sum;
      ans = i;
    }
  }
  cout << ans;

  return 0;
}
