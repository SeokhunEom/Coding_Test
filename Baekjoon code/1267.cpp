#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a, ysik = 0, msik = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    ysik += ((a / 30) + 1) * 10;
    msik += ((a / 60) + 1) * 15;
  }
  if(ysik < msik) 
    cout << "Y " << ysik << endl;
  else if (ysik == msik)
    cout << "Y M " << ysik << endl;
  else
    cout << "M " << msik << endl;
    
  return 0;
}