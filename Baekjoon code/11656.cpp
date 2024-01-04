#include <bits/stdc++.h>
using namespace std;

int len;
string arr[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> arr[0];
  len = arr[0].length();
  for (int i = 1; i < len; i++) arr[i] = arr[0].substr(i, len);
  sort(arr, arr + len);
  for (int i = 0; i < len; i++) cout << arr[i] << '\n';

  return 0;
}
