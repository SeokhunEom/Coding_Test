#include <bits/stdc++.h>
using namespace std;

int N, first, last, ans = INT_MAX, sum, ans_first, ans_last;
int arr[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  first = 0;
  last = N - 1;
  while (first < last) {
    sum = arr[first] + arr[last];
    if (sum == 0) {
      ans = 0;
      ans_first = arr[first];
      ans_last = arr[last];
      break;
    }
    if (abs(sum) < abs(ans)) {
      ans = sum;
      ans_first = arr[first];
      ans_last = arr[last];
    }
    if (sum < 0)
      first++;
    else
      last--;
  }
  cout << ans_first << " " << ans_last;

  return 0;
}
