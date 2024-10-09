#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int N, C, a, cnt;
map<int, int> m1;
map<int, int> m2;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return m2[a.first] < m2[b.first];
  }
  return a.second > b.second;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> a;
    m1[a]++;
    if (m1[a] == 1) {
      m2[a] = cnt++;
    }
  }

  for (auto it = m1.begin(); it != m1.end(); it++) {
    v.push_back({it->first, it->second});
  }
  stable_sort(v.begin(), v.end(), compare);
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].second; j++) {
      cout << v[i].first << " ";
    }
  }

  return 0;
}