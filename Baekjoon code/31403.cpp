#include <bits/stdc++.h>
using namespace std;

int A, B, C;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> C;
  cout << A + B - C << '\n';
  cout << stoi(to_string(A) + to_string(B)) - C;

  return 0;
}
