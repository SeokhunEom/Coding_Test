#include <bits/stdc++.h>
using namespace std;

int N, M, H, a, b, ans = -1;
bool ladder[30][10];

void func(int cnt, int idx);
bool test(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> H;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    ladder[a - 1][b - 1] = true;
  }
  func(0, 0);
  cout << ans;

  return 0;
}

void func(int cnt, int idx) {
  if (cnt >= 4) return;
  if (test()) {
    if (ans == -1)
      ans = cnt;
    else
      ans = ans > cnt ? cnt : ans;
    return;
  }
  for (int i = idx; i < (N - 1) * H; i++) {
    int x = i / (N - 1);
    int y = i % (N - 1);
    if (ladder[x][y]) continue;
    if (y > 0 && ladder[x][y - 1]) continue;
    if (y < N - 2 && ladder[x][y + 1]) continue;
    ladder[x][y] = 1;
    func(cnt + 1, i + 1);
    ladder[x][y] = 0;
  }
}

bool test(void) {
  for (int x = 0; x < N; x++) {
    int start = x;
    for (int y = 0; y < H; y++) {
      if (ladder[y][x])
        x++;
      else if (x > 0 && ladder[y][x - 1])
        x--;
    }
    if (x != start) return false;
  }

  return true;
}