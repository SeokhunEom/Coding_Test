#include <bits/stdc++.h>

using namespace std;

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i += 4) cout << "long ";
  cout << "int";

  return 0;
}
