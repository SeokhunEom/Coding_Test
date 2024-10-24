#include <iostream>
using namespace std;

int X, N, a, b, sum;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> X;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    sum += a * b;
  }
  if (sum == X) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}