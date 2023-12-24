#include <bits/stdc++.h>
using namespace std;

int N, minres = 1000000001, maxres = -1000000001;
int num[11];
int op[4];
int choice[10] = {0, 0, 3, 1, 2};

void func(int cnt, int res);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> num[i];
  cin >> op[0] >> op[1] >> op[2] >> op[3];
  func(0, num[0]);
  cout << maxres << '\n' << minres;

  return 0;
}

void func(int cnt, int res) {
  if (cnt == N - 1) {
    if (res > maxres) maxres = res;
    if (res < minres) minres = res;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (op[i] == 0) continue;
    op[i]--;
    if (i == 0)
      func(cnt + 1, res + num[cnt + 1]);
    else if (i == 1)
      func(cnt + 1, res - num[cnt + 1]);
    else if (i == 2)
      func(cnt + 1, res * num[cnt + 1]);
    else
      func(cnt + 1, res / num[cnt + 1]);
    op[i]++;
  }
}