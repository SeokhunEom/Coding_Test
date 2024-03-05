#include <bits/stdc++.h>
using namespace std;

int A, B, V, ans = 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> V;

  ans += (V - A) / (A - B);
  if ((V - A) % (A - B) != 0) ans++;
  if (A >= V)
    cout << "1";
  else
    cout << ans;

  return 0;
}
