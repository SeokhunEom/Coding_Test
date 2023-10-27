#include <bits/stdc++.h>
using namespace std;

void dfs(int depth);

int N, M;
int arr[9];
bool visited[9];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  dfs(0);

  return 0;
}

void dfs(int depth) {
  if (depth == M) {
    for (int i = 0; i < M; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      arr[depth] = i;
      dfs(depth + 1);
      visited[i] = false;
    }
  }
}