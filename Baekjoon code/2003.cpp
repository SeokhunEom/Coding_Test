#include <bits/stdc++.h>
using namespace std;

int N, M, first, last, sum, ans;
int A[10000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> A[i];
  sum = A[0];
  while (last < N) {
    if (sum < M) {
      last++;
      sum += A[last];
    } else if (sum == M) {
      ans++;
      last++;
      sum += A[last];
    } else {
      sum -= A[first];
      first++;
      if (first > last) {
        last = first;
        sum = A[first];
      }
    }
  }
  while (first < N - 1) {
    sum -= A[first];
    first++;
    if (sum == M) ans++;
  }

  cout << ans;

  return 0;
}
