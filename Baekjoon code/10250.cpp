#include <bits/stdc++.h>
using namespace std;

int T, H, W, N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> H >> W >> N;
    int floor = N % H;
    if (floor == 0) floor = H;
    int room = N / H + 1;
    if (N % H == 0) room = N / H;
    cout << floor * 100 + room << '\n';
  }

  return 0;
}
