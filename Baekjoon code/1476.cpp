#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int e, s, m, year = 1;

  cin >> e >> s >> m;

  while (1) {
    if (((year - e) % 15 == 0) && ((year - s) % 28 == 0) &&
        ((year - m) % 19 == 0)) {
      break;
    }
    year++;
  }

  cout << year;

  return 0;
}