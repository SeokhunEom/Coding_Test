#include <bits/stdc++.h>
using namespace std;

int arr[8];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 8; i++) cin >> arr[i];
  if (arr[0] == 1) {
    bool flag = true;
    for (int i = 1; i < 8; i++) {
      if (arr[i] != i + 1) {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "ascending";
    else
      cout << "mixed";
  } else if (arr[0] == 8) {
    bool flag = true;
    for (int i = 1; i < 8; i++) {
      if (arr[i] != 8 - i) {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "descending";
    else
      cout << "mixed";
  } else {
    cout << "mixed";
  }

  return 0;
}
