#include <bits/stdc++.h>
using namespace std;

int T, N, M, K;

int func(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--) {
    cin >> N >> M >> K;
    cout << func() << '\n';
  }

  return 0;
}

int func(void) {
  int a = N, b = M, c = 0, d = 0, ans = 0;
  while (ans < 21 && c != N) {
    ans++;
    int x = min(a, b * K);
    int y = min(b, (x / K) + 1);
    a -= x;
    b -= y;
    c += x;
    d += y;
    if (c == N) break;
    if (b >= y) continue;
    ans++;
    int z = 1;
    int w = d;
    a += z;
    b += w;
    c -= z;
    d -= w;
  }
  return ans > 20 ? -1 : ans;
}