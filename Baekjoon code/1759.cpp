#include <bits/stdc++.h>
using namespace std;

int L, C;
char arr[16];
char ans[16];
bool vis[16];
void func(int cnt, int idx);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> C;
  for (int i = 0; i < C; i++) cin >> arr[i];
  sort(arr, arr + C);
  func(0, 0);

  return 0;
}

void func(int cnt, int idx) {
  if (cnt == L) {
    int a = 0;
    for (int i = 0; i < L; i++) {
      if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' ||
          ans[i] == 'u')
        a++;
    }
    if (a < 1 || L - a < 2) return;
    for (int i = 0; i < L; i++) cout << ans[i];
    cout << "\n";
    return;
  }
  for (int i = idx; i < C; i++) {
    if (vis[i]) continue;
    vis[i] = true;
    ans[cnt] = arr[i];
    func(cnt + 1, i + 1);
    vis[i] = false;
  }
}
