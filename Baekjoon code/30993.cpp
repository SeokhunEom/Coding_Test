#include <bits/stdc++.h>
using namespace std;

int N, A, B, C;
long long res1 = 1, res2 = 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> A >> B >> C;
  for (int i = 0; i < A; i++) {
    res1 *= N;
    res2 *= i + 1;
    N--;
  }
  for (int i = 0; i < B; i++) {
    res1 *= N;
    res2 *= i + 1;
    N--;
  }
  cout << res1 / res2;

  return 0;
}