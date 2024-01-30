#include <bits/stdc++.h>
using namespace std;

int N, t;
int arr[1000];
vector<int> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) v.push_back(arr[i] + arr[j]);
  }
  sort(v.begin(), v.end());

  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      t = arr[i] - arr[j];
      if (binary_search(v.begin(), v.end(), t)) {
        cout << arr[i];
        return 0;
      }
    }
  }

  return 0;
}
