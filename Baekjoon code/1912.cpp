#include <bits/stdc++.h>
using namespace std;

int n, a, sum, ans = INT_MIN;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sum += a;
    ans = max(ans, sum);
    if (sum < 0) sum = 0;
  }
  cout << ans;

  return 0;
}
