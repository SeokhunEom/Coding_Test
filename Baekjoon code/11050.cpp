#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[11][11];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 1; i <= 10; i++) {
    arr[i][0] = arr[i][i] = 1;
    for (int j = 1; j < i; j++) arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]);
  }
  cout << arr[N][K];

  return 0;
}
