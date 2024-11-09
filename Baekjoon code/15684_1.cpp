#include <iostream>
using namespace std;

int N, M, H, a, b, ans = -1;
bool arr[31][11];

bool check(void) {
  for (int i = 0; i < N; i++) {
    int x = i;
    for (int j = 0; j < H; j++) {
      if (arr[j][i]) {
        i++;
      } else if (i > 0 && arr[j][i - 1]) {
        i--;
      }
    }
    if (i != x) return false;
  }

  return true;
}

void func(int cnt, int idx) {
  if (cnt >= 4) return;

  if (check()) {
    if (ans == -1) {
      ans = cnt;
    } else {
      ans = min(ans, cnt);
    }
    return;
  }

  for (int i = idx; i < (N - 1) * H; i++) {
    int x = i / (N - 1);
    int y = i % (N - 1);

    if (arr[x][y]) continue;
    if (y > 0 && arr[x][y - 1]) continue;
    if (y < N - 2 && arr[x][y + 1]) continue;

    arr[x][y] = 1;
    func(cnt + 1, i + 1);
    arr[x][y] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> H;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    arr[a - 1][b - 1] = true;
  }
  func(0, 0);
  cout << ans;

  return 0;
}