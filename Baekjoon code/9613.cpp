#include <bits/stdc++.h>
using namespace std;

int t, n;
long long sum;
int arr[100];

int gcd(int a, int b);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) cin >> arr[j];
    sum = 0;
    for (int a = 0; a < n; a++) {
      for (int b = a + 1; b < n; b++) {
        if (arr[a] > arr[b])
          sum += gcd(arr[a], arr[b]);
        else
          sum += gcd(arr[b], arr[a]);
      }
    }
    cout << sum << '\n';
  }

  return 0;
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}