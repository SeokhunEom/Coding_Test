#include <iostream>
using namespace std;

int N, M, J, a, startX, endX, ans;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> J;
  startX = 1;
  endX = M;
  for (int i = 0; i < J; i++) {
    cin >> a;
    if (a < startX) {
      ans += startX - a;
      startX = a;
      endX = a + M - 1;
    } else if (a > endX) {
      ans += a - endX;
      endX = a;
      startX = a - M + 1;
    }
  }
  cout << ans;

  return 0;
}