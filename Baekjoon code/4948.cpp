#include <bits/stdc++.h>
using namespace std;

int n, ans;
int arr[246913];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  arr[0] = arr[1] = 0;
  for (int i = 2; i <= 246912; i++) arr[i] = 1;
  for (int i = 2; i <= 246912; i++) {
    if (arr[i] == 0) continue;
    for (int j = i + i; j <= 246912; j += i) arr[j] = 0;
  }

  while (1) {
    cin >> n;
    if (n == 0) break;
    ans = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
      ans += arr[i];
    }
    cout << ans << '\n';
  }

  return 0;
}
