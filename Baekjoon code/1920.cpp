#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr1[100000];
int arr2[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr1[i];
  cin >> M;
  for (int i = 0; i < M; i++) cin >> arr2[i];

  sort(arr1, arr1 + N);
  for (int i = 0; i < M; i++) {
    int start = 0;
    int end = N - 1;
    int mid = (start + end) / 2;
    while (start <= end) {
      if (arr1[mid] == arr2[i]) {
        cout << 1 << '\n';
        break;
      } else if (arr1[mid] < arr2[i]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
      mid = (start + end) / 2;
    }
    if (start > end) cout << 0 << '\n';
  }

  return 0;
}
