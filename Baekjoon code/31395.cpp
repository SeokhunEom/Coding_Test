#include <bits/stdc++.h>
using namespace std;

int N, len;
int arr[200000];
long long ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  for (int i = 0; i < N; i++) {
    if (i == 0 || arr[i] > arr[i - 1])
      len++;
    else
      len = 1;
    ans += len;
  }
  cout << ans;

  return 0;
}
