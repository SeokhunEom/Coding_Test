#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x, t[1000001] = {0, }, a[100000] = {0, }, r = 0;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  cin >> x;
  for(int i = 0; i < n; i++) {
    if(x - a[i] >= 0 && x - a[i] <= 1000000)
    r += t[x - a[i]];
    t[a[i]]++;
  }
  cout << r;

  return 0;
}