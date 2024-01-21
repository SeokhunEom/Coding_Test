#include <bits/stdc++.h>
using namespace std;

int N, prevNum, curNum, ans;
int arr[51];

bool compare(int a, int b) {
  if (a == 0)
    return false;
  else if (b == 0)
    return true;
  else if (a > 0 && b > 0)
    return a > b;
  else if (a < 0 && b < 0)
    return a < b;
  else
    return a > b;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N, compare);

  prevNum = arr[0];
  for (int i = 1; i < N; i++) {
    curNum = arr[i];
    if (curNum == 1) {
      ans += prevNum + curNum;
      prevNum = arr[i + 1];
      i++;
    } else if (prevNum * curNum > 0 || prevNum < 0 && curNum == 0) {
      ans += prevNum * curNum;
      prevNum = arr[i + 1];
      i++;
    } else {
      ans += prevNum;
      prevNum = curNum;
    }
  }
  ans += prevNum;
  cout << ans;

  return 0;
}
