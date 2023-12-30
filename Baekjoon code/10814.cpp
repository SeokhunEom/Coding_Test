#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, string> arr[100000];

bool compare(pair<int, string> a, pair<int, string> b) {
  return a.first < b.first;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
  stable_sort(arr, arr + N, compare);
  for (int i = 0; i < N; i++)
    cout << arr[i].first << ' ' << arr[i].second << '\n';

  return 0;
}
