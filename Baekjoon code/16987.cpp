#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> egg[8];

void func(int idx);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> egg[i].first >> egg[i].second;
  func(0);
  cout << ans;

  return 0;
}

void func(int idx) {
  // cout << "\n" << idx << "=========\n";
  // for (int i = 0; i < N; i++)
  //   cout << egg[i].first << " " << egg[i].second << "\n";

  if (idx == N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (egg[i].first <= 0) cnt++;
    }
    if (cnt > ans) ans = cnt;
    return;
  }
  bool flag = false;
  for (int i = 0; i < N; i++) {
    if (i == idx) continue;
    if (egg[i].first <= 0) continue;
    if (egg[idx].first <= 0) continue;
    flag = true;
    egg[i].first -= egg[idx].second;
    egg[idx].first -= egg[i].second;
    func(idx + 1);
    egg[i].first += egg[idx].second;
    egg[idx].first += egg[i].second;
  }
  if (flag == false) func(idx + 1);
}
