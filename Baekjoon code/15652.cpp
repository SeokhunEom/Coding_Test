#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8];

void func(int idx);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  func(0);

  return 0;
}

void func(int idx) {
  if (idx == M) {
    for (int i = 0; i < M; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  int start = idx > 0 ? arr[idx - 1] : 1;
  for (int i = start; i <= N; i++) {
    arr[idx] = i;
    func(idx + 1);
  }
}