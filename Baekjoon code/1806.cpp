#include <bits/stdc++.h>
using namespace std;

int N, S, idx1, idx2, ans = INT_MAX, sum;
int arr[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> arr[i];

  sum = arr[0];
  while (idx1 <= idx2 && idx2 < N) {
    if (sum < S) {
      idx2++;
      sum += arr[idx2];
    } else {
      ans = min(ans, idx2 - idx1 + 1);
      sum -= arr[idx1];
      idx1++;
    }
  }
  cout << (ans == INT_MAX ? 0 : ans);

  return 0;
}
