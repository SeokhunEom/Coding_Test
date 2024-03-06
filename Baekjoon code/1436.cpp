#include <bits/stdc++.h>
using namespace std;

int N, cur = 0, num;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (num = 666; cur < N; num++) {
    if (to_string(num).find("666") != string::npos) cur++;
  }
  cout << num - 1;

  return 0;
}
