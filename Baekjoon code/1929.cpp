#include <bits/stdc++.h>
using namespace std;

int M, N;
bool arr[1000001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  arr[1] = true;
  for (int i = 2; i < 1000001; i++) {
    if (arr[i]) continue;
    for (int j = i * 2; j < 1000001; j += i) arr[j] = true;
  }

  cin >> M >> N;
  for (int i = M; i <= N; i++) {
    if (!arr[i]) cout << i << '\n';
  }

  return 0;
}
