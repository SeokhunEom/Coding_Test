#include <bits/stdc++.h>
using namespace std;

int N, a, b, c;
string s;
tuple<string, int, int, int> arr[100001];

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
  string a0 = get<0>(a), b0 = get<0>(b);
  int a1 = get<1>(a), a2 = get<2>(a), a3 = get<3>(a);
  int b1 = get<1>(b), b2 = get<2>(b), b3 = get<3>(b);
  if (a1 == b1 && a2 == b2 && a3 == b3) return a0 < b0;
  if (a1 == b1 && a2 == b2) return a3 > b3;
  if (a1 == b1) return a2 < b2;
  return a1 > b1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s >> a >> b >> c;
    arr[i] = {s, a, b, c};
  }
  sort(arr, arr + N, compare);
  for (int i = 0; i < N; i++) {
    cout << get<0>(arr[i]) << '\n';
  }

  return 0;
}
