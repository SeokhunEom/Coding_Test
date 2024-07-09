#include <bits/stdc++.h>
using namespace std;

int n, m, i, j, k;
int arr[10000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int t = 0; t < n; t++) cin >> arr[t];
  for (int t = 0; t < m; t++) {
    cin >> i >> j >> k;
    vector<int> v;
    for (int l = i - 1; l < j; l++) v.push_back(arr[l]);
    sort(v.begin(), v.end());
    cout << v[k - 1] << '\n';
  }
}
