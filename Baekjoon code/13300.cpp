#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, arr[12] = {0, }, a, b, r = 0;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    if(a)
      arr[5 + b]++;
    else
      arr[b - 1]++;
  }
  for(int i = 0; i < 12; i++) {
    if(arr[i] % k)
      r++;
    r += (arr[i] / k);
  }
  cout << r;

  return 0;
}