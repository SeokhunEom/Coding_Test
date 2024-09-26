#include <iostream>
using namespace std;

int N, M, t, ans;
int arr[100005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> t;
    arr[t]++;
  }

  for (int i = 1; i <= 100000; i++) {
    if (M - i <= 0 || i > M - i || M - i > 100000) continue;
    int a = arr[i];
    int b = arr[M - i];
    if (i == M - i) {
      ans += a / 2;
    } else {
      ans += min(a, b);
    }
  }

  cout << ans;

  return 0;
}