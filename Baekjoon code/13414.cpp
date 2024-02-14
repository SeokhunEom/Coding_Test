#include <bits/stdc++.h>
using namespace std;

int K, L;
string num;
map<string, int> m;
vector<pair<string, int>> v;

bool compare(pair<string, int> a, pair<string, int> b) {
  return a.second < b.second;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K >> L;
  for (int i = 1; i <= L; i++) {
    cin >> num;
    m[num] = i;
  }
  for (auto item : m) v.push_back(item);
  sort(v.begin(), v.end(), compare);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << '\n';
    if (i == K - 1) break;
  }

  return 0;
}
