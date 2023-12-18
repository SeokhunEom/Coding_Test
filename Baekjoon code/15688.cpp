#include <bits/stdc++.h>
using namespace std;

int N, n;
int arr[2000001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> n;
    arr[n + 1000000]++;
  }
  for (int i = 0; i <= 2000000; i++)
    while (arr[i]-- > 0) cout << i - 1000000 << "\n";

  return 0;
}
