#include <iostream>
#include <queue>
using namespace std;

int N, K, idx = 1;
queue<int> q;
int visited[2][500001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  if (N == K) {
    cout << 0;
    return 0;
  }
  q.push(N);

  while (!q.empty()) {
    K += idx;

    if (K > 500000) {
      cout << -1;
      return 0;
    }
    if (visited[idx % 2][K] == 1) {
      cout << idx;
      return 0;
    }

    int len = q.size();
    for (int i = 0; i < len; i++) {
      int cur = q.front();
      q.pop();

      for (int nx : {cur - 1, cur + 1, 2 * cur}) {
        if (nx == K) {
          cout << idx;
          return 0;
        }
        if (nx < 0 || nx > 500000) continue;
        if (visited[idx % 2][nx] == 1) continue;
        visited[idx % 2][nx] = 1;
        q.push(nx);
      }
    }
    idx++;
  }

  return 0;
}