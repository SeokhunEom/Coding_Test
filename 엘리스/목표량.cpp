#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t;
  int arr1[10];
  int arr2[10];
  for (int i = 0; i < 10; i++) arr1[i] = 0;

  cin >> n;
  t = n;
  while (t > 0) {
    arr1[t % 10]++;
    t /= 10;
  }

  for (int i = n + 1; i <= 999999; i++) {
    for (int j = 0; j < 10; j++) arr2[j] = 0;

    int num = i;
    while (num > 0) {
      arr2[num % 10]++;
      num /= 10;
    }

    bool is_same = true;
    for (int j = 0; j < 10; j++) {
      if (arr1[j] != arr2[j]) {
        is_same = false;
        break;
      }
    }

    if (is_same == true) {
      cout << i;
      break;
    }
  }

  return 0;
}
