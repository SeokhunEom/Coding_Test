#include <bits/stdc++.h>

using namespace std;

int n;
int arr[256];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= 255; i++) {
    arr[i] = i * i;
    if (arr[i] == n) {
      cout << 1;
      return 0;
    }
  }

  for (int i = 1; i <= 255; i++) {
    if (arr[i] > n) break;
    for (int j = 1; j <= 255; j++) {
      if (arr[i] + arr[j] > n) break;
      if (arr[i] + arr[j] == n) {
        cout << 2;
        return 0;
      }
    }
  }

  for (int i = 1; i <= 255; i++) {
    if (arr[i] > n) break;
    for (int j = 1; j <= 255; j++) {
      if (arr[i] + arr[j] > n) break;
      for (int k = 1; k <= 255; k++) {
        if (arr[i] + arr[j] + arr[k] > n) break;
        if (arr[i] + arr[j] + arr[k] == n) {
          cout << 3;
          return 0;
        }
      }
    }
  }

  cout << 4;

  return 0;
}
