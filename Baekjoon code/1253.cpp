#include <algorithm>
#include <iostream>
using namespace std;

int N, ans, tmp;
int arr[2001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + N);

  for (int i = 0; i < N; i++) {
    tmp = arr[i];
    int l = 0, r = N - 1, sum;
    while (l < r) {
      sum = arr[l] + arr[r];
      if (sum == tmp) {
        if (l != i && r != i) {
          ans++;
          break;
        } else if (l == i) {
          l++;
        } else if (r == i) {
          r--;
        }
      } else if (sum < tmp) {
        l++;
      } else {
        r--;
      }
    }
  }

  cout << ans;

  return 0;
}