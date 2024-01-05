#include <bits/stdc++.h>
using namespace std;

int T, N, M, idx, cnt;
int a[20000], b[20000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N >> M;
    for (int j = 0; j < N; j++) cin >> a[j];
    for (int j = 0; j < M; j++) cin >> b[j];
    sort(a, a + N);
    sort(b, b + M);

    idx = 0;
    cnt = 0;
    for (int j = 0; j < N; j++) {
      while (b[idx] < a[j] && idx < M) idx++;
      cnt += idx;
    }
    cout << cnt << '\n';
  }

  return 0;
}
