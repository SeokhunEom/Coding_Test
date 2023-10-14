#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d, r;
  for(int i = 0; i < 3; i++){
    cin >> a >> b >> c >> d;
    r = a + b + c + d;

    if (r == 0)
      cout << 'D' << '\n';
    else if (r == 1)
      cout << 'C' << '\n';
    else if (r == 2)
      cout << 'B' << '\n';
    else if (r == 3)
      cout << 'A' << '\n';
    else
      cout << 'E' << '\n';
  }

  return 0;
}