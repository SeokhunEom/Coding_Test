#include <bits/stdc++.h>
using namespace std;

unsigned long long n, t;
string s;
unsigned long long arr[1000001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    s = to_string(t);
    reverse(s.begin(), s.end());
    t = stoull(s);
    arr[i] = t;
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) cout << arr[i] << '\n';
  return 0;
}
