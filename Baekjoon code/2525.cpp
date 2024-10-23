#include <iostream>
using namespace std;

int A, B, C, t, ret1, ret2;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;
  t = A * 60 + B + C;
  ret1 = t / 60 % 24;
  ret2 = t % 60;
  cout << ret1 << " " << ret2;

  return 0;
}