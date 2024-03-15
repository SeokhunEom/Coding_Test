#include <bits/stdc++.h>

using namespace std;

int Q, K, R, B, N, P;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K >> Q >> R >> B >> N >> P;
  cout << (1 - K) << " " << (1 - Q) << " " << (2 - R) << " " << (2 - B) << " "
       << (2 - N) << " " << (8 - P);

  return 0;
}
