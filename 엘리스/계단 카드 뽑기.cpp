#include <bits/stdc++.h>
using namespace std;

int N, ans;
int A[50000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  for (int start = 0; start < N; start++) {
    for (int end = start; end < N; end++) {
      vector<int> temp(N + 1, 0);
      int len = end - start;
      bool flag = true;

      for (int num = start; num <= end; num++) {
        for (int i = 1; i <= num; i++) {
          temp[i]++;
        }
      }

      for (int i = 1; i <= N; i++) {
        if (temp[i] < len - i) {
          flag = false;
          break;
        }
      }

      if (flag) ans = max(ans, len);
    }
  }

  cout << ans;

  return 0;
}
