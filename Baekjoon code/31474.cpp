#include <bits/stdc++.h>
using namespace std;

int N;
unsigned long long ans = 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = N / 2 + 1; i <= N; i++) ans *= i;
  for (int i = 0; i < N / 2; i++) ans /= 2;
  cout << ans;

  return 0;
}
