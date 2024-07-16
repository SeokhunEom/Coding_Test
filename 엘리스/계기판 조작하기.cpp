#include <bits/stdc++.h>
using namespace std;

int N, K, len;
int temp[] = {10,      102,      1023,      10234,     102345,
              1023456, 10234567, 102345678, 1023456789};

int calcK(int n) {
  int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int ret = 0;

  while (n > 0) {
    arr[n % 10]++;
    n /= 10;
  }

  for (int i = 0; i < 10; i++) {
    if (arr[i] != 0) ret++;
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  len = to_string(N).size();
  if (len < K) {
    for (int t : temp) {
      if (calcK(t) == K && N < t) {
        cout << t;
        break;
      }
    }
  } else {
    while (true) {
      N++;
      if (calcK(N) == K) {
        cout << N;
        break;
      }
    }
  }

  return 0;
}
