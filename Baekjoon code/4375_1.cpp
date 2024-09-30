#include <iostream>
using namespace std;

long long n, ans, num;
long long arr[10001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> n) {
    if (arr[n] != 0) {
      cout << arr[n] << '\n';
      continue;
    }
    num = 1;
    ans = 1;
    while (true) {
      num %= n;
      if (num == 0) {
        break;
      }
      num = (num * 10 + 1) % n;
      ans++;
    }
    arr[n] = ans;
    cout << ans << '\n';
  }

  return 0;
}