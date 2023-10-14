#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a[9] = {0, }, max = 0;
  cin >> n;
  while(n) {
    if(n % 10 == 9)
      a[6]++;
    else
      a[n % 10]++;
    n /= 10;
  }
  if(a[6] % 2)
    a[6]++;
  a[6] /= 2;
  for(int i = 0; i < 9; i++) {
    if(a[i] > max)
      max = a[i];
  }
  cout << max;

  return 0;
}