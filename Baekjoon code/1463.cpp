#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) arr[i] = INT_MAX;
  arr[1] = 0;
  for (int i = 1; i < N; i++) {
    if (arr[i] + 1 < arr[i + 1]) arr[i + 1] = arr[i] + 1;
    if (i * 2 <= N && arr[i] + 1 < arr[i * 2]) arr[i * 2] = arr[i] + 1;
    if (i * 3 <= N && arr[i] + 1 < arr[i * 3]) arr[i * 3] = arr[i] + 1;
  }
  cout << arr[N];

  return 0;
}
