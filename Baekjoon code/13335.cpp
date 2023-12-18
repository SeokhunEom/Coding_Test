#include <bits/stdc++.h>
using namespace std;

int n, w, L, ans;
int truck[1001];
int bridge[102];

void func(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> w >> L;
  for (int i = 0; i < n; i++) cin >> truck[i];
  func();
  cout << ans;

  return 0;
}

void func(void) {
  for (int i = 0; i < n;) {
    ans++;
    int sum = 0;
    for (int j = 0; j < w; j++) sum += bridge[j];

    if (sum + truck[i] <= L)
      bridge[0] = truck[i++];
    else
      bridge[0] = 0;

    bridge[w] = 0;
    for (int j = w - 1; j >= 0; j--) {
      bridge[j + 1] = bridge[j];
      bridge[j] = 0;
    }

    for (int i = 0; i <= w; i++) {
      cout << bridge[i] << " ";
    }
    cout << "\n";
  }
  ans += w;
}