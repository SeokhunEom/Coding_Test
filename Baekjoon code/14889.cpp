#include <bits/stdc++.h>
using namespace std;

int N, ans = INT_MAX;
int S[20][20];
int team[20];
int choice[10];

void func(int cnt, int idx);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> S[i][j];
  func(0, 0);
  cout << ans;

  return 0;
}

void func(int cnt, int idx) {
  if (cnt == N / 2) {
    for (int i = 0; i < N; i++) team[i] = 0;
    for (int i = 0; i < N / 2; i++) team[choice[i]] = 1;
    int start = 0, link = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (i == j) continue;
        if ((team[i] == team[j]) && team[i] == 1)
          start += S[i][j] + S[j][i];
        else if ((team[i] == team[j]) && team[i] == 0)
          link += S[i][j] + S[j][i];
      }
    }
    int diff = abs(start - link);
    if (diff < ans) ans = diff;
    return;
  }
  for (int i = idx; i < N; i++) {
    choice[cnt] = i;
    func(cnt + 1, i + 1);
  }
}