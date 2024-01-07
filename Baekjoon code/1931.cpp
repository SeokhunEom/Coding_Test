#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> arr[100000];

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
  sort(arr, arr + N, compare);
  int time = 0;
  for (int i = 0; i < N; i++) {
    if (time <= arr[i].first) {
      time = arr[i].second;
      ans++;
    }
  }
  cout << ans;

  return 0;
}
