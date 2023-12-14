#include <bits/stdc++.h>
using namespace std;

int N, M, ans = 10000, c;
int city[51][51];
pair<int, int> chicken[13];
int choice[13];

void func(int cnt, int idx);
int getDist(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> city[i][j];
      if (city[i][j] == 2) {
        chicken[c++] = {i, j};
      }
    }
  }

  func(0, 0);
  cout << ans;

  return 0;
}

void func(int cnt, int idx) {
  if (cnt == M) {
    int dist = getDist();
    if (ans > dist) ans = dist;
    return;
  }
  for (int i = idx; i < c; i++) {
    if (choice[i] != 0) continue;
    choice[cnt] = i;
    func(cnt + 1, i + 1);
    choice[cnt] = 0;
  }
}

int getDist() {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (city[i][j] == 1) {
        int dist = 10000;
        for (int k = 0; k < M; k++) {
          int cx = chicken[choice[k]].first;
          int cy = chicken[choice[k]].second;
          int temp = abs(i - cx) + abs(j - cy);
          if (dist > temp) dist = temp;
        }
        sum += dist;
      }
    }
  }
  return sum;
}