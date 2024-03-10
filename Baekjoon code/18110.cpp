#include <bits/stdc++.h>

using namespace std;

int n, cut, sum;
int arr[300000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  cut = round((double)n * 0.15);
  for (int i = cut; i < n - cut; i++) sum += arr[i];
  cout << round((double)sum / (n - cut * 2));

  return 0;
}
