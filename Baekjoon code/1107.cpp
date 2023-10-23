#include <bits/stdc++.h>
using namespace std;

bool isContainK(int num, int k);
int getDigit(int num);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t, k, ans = 1000001, temp;
  int arr[1000001] = {0};

  cin >> n >> t;
  for (int i = 0; i < t; i++) {
    cin >> k;
    for (int i = 0; i < 1000001; i++) {
      if (arr[i] == 0 && isContainK(i, k)) {
        arr[i] = -1;
      }
    }
    arr[100] = 0;
  }

  for (int i = 0; i < 1000001; i++) {
    if (arr[i] != -1) {
      if (i == 100) {
        temp = abs(i - n);
      } else {
        temp = abs(i - n) + getDigit(i);
      }
      if (ans > temp) {
        ans = temp;
      }
    }
  }

  cout << ans;

  return 0;
}

bool isContainK(int num, int k) {
  int digit = getDigit(num);

  for (int i = 0; i < digit; i++) {
    if (num % 10 == k) {
      return true;
    }
    num /= 10;
  }

  return false;
}

int getDigit(int num) {
  int ret = 0;

  while (1) {
    ret++;
    num /= 10;
    if (num == 0) {
      return ret;
    }
  }
}