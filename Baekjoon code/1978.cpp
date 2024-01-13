#include <bits/stdc++.h>
using namespace std;

int N, a, ans;
bool arr[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  arr[1] = true;
  for (int i = 2; i < 1001; i++) {
    if (arr[i]) continue;
    for (int j = i * 2; j < 1001; j += i) arr[j] = true;
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (!arr[a]) ans++;
  }
  cout << ans;

  return 0;
}
