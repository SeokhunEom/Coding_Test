#include <bits/stdc++.h>

using namespace std;

int N, M;
string arr1[500000];
string arr2[500000];
vector<string> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> arr1[i];
  for (int i = 0; i < M; i++) cin >> arr2[i];
  sort(arr1, arr1 + N);
  sort(arr2, arr2 + M);

  for (int i = 0; i < N; i++) {
    if (binary_search(arr2, arr2 + M, arr1[i])) v.push_back(arr1[i]);
  }

  cout << v.size() << '\n';
  for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';

  return 0;
}
