#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a, b, i = 1;
  cin >> a >> b;
  if(a > b) {
    long long temp = a;
    a = b;
    b = temp;
  }
  if(a == b || b - a == 1){
    cout << 0 << '\n';
  }
  else {
    cout << b - a - 1 << '\n';
    while(1) {
      cout << a + i << ' ';
      i++;
      if(a + i == b)
        break;
    }
  }

  return 0;
}