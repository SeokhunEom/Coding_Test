#include <bits/stdc++.h>
using namespace std;

int N, M, t;
int arr[500000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> t;
    cout << binary_search(arr, arr + N, t) << " ";
  }

  return 0;
}
