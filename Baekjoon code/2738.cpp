#include <bits/stdc++.h>
using namespace std;

int N, M, t;
int arr1[100][100];
int arr2[100][100];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> arr1[i][j];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> arr2[i][j];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M - 1; j++) cout << arr1[i][j] + arr2[i][j] << ' ';
    cout << arr1[i][M - 1] + arr2[i][M - 1] << '\n';
  }

  return 0;
}
