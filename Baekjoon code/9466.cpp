#include <bits/stdc++.h>
using namespace std;

int T, n;
int arr[100001];
int visited[100001];

void bfs(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    for (int j = 1; j <= n; j++) {
      cin >> arr[j];
      if (arr[j] == j) {
        visited[j] = -1;
      } else {
        visited[j] = 0;
      }
    }
    bfs();
  }

  return 0;
}

void bfs(void) {
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      int cur = i;
      while (1) {
        visited[cur] = i;
        cur = arr[cur];

        if (visited[cur] == i) {
          while (visited[cur] != -1) {
            visited[cur] = -1;
            cur = arr[cur];
          }
          break;
        } else if (visited[cur] != 0) {
          break;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i] != -1) {
      ans++;
    }
  }
  cout << ans << "\n";
}
