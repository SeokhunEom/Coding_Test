#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull A, B, C, ans;

ull func(ull a, ull b) {
  if (b == 0) {
    return 1;
  }
  ull t = func(a, b / 2);
  t = (t * t) % C;
  if (b % 2 == 0) {
    return t;
  } else {
    return t * a % C;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;
  ans = func(A, B);
  cout << ans;

  return 0;
}
