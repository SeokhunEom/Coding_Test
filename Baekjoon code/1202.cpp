#include <bits/stdc++.h>
using namespace std;

long long ans;
int N, K, a, m, v;
pair<int, int> arr[300000];
multiset<int> ms;

bool compare(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
  for (int i = 0; i < K; i++) {
    cin >> a;
    ms.insert(a);
  }
  sort(arr, arr + N, compare);

  for (int i = N - 1; i >= 0; i--) {
    m = arr[i].first;
    v = arr[i].second;
    auto it = ms.lower_bound(m);
    if (it == ms.end()) continue;
    ans += v;
    ms.erase(it);
  }

  cout << ans;

  return 0;
}
