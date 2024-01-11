#include <bits/stdc++.h>
using namespace std;

int N, a, ans;
vector<int> A, B;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    A.push_back(a);
  }
  for (int i = 0; i < N; i++) {
    cin >> a;
    B.push_back(a);
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end(), greater<int>());
  for (int i = 0; i < N; i++) ans += A[i] * B[i];
  cout << ans;

  return 0;
}
