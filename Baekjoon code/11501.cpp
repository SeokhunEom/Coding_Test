#include <bits/stdc++.h>
using namespace std;

int T, N, price;
long long ans;
int arr[1000001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++) {
    ans = 0;
    price = -1;

    cin >> N;
    for (int j = 0; j < N; j++) cin >> arr[j];

    for (int j = N - 1; j >= 0; j--) {
      if (arr[j] > price)
        price = arr[j];
      else
        ans += (price - arr[j]);
    }

    cout << ans << "\n";
  }

  return 0;
}
