#include <bits/stdc++.h>
using namespace std;

int N, C, a;
map<int, pair<int, int>> m;
vector<pair<int, pair<int, int>>> v;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  if (a.second.first == b.second.first)
    return a.second.second < b.second.second;
  return a.second > b.second;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (m.find(a) == m.end()) {
      m[a] = {1, i};
    } else {
      m[a] = {m[a].first + 1, m[a].second};
    }
  }
  for (pair<int, pair<int, int>> item : m) v.push_back(item);
  stable_sort(v.begin(), v.end(), compare);
  for (pair<int, pair<int, int>> item : v)
    for (int i = 0; i < item.second.first; i++) cout << item.first << ' ';

  return 0;
}
