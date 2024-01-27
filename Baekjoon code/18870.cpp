#include <bits/stdc++.h>
using namespace std;

int N, temp, idx = 0;
int arr1[1000000];
int arr2[1000000];
int arr3[1000000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr1[i];
    arr2[i] = arr1[i];
  }

  sort(arr2, arr2 + N);
  temp = arr2[0];
  arr3[0] = arr2[0];
  for (int i = 1; i < N; i++) {
    if (arr2[i] == temp) continue;
    arr3[++idx] = arr2[i];
    temp = arr2[i];
  }

  for (int i = 0; i < N; i++)
    cout << lower_bound(arr3, arr3 + idx, arr1[i]) - arr3 << ' ';

  return 0;
}
