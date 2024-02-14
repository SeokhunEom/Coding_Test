#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

int solution(int k, vector<int> tangerine) {
  int answer = 0, idx = 0;

  map<int, int> m;
  vector<pair<int, int>> v;
  for (int tan : tangerine) {
    if (m.find(tan) == m.end())
      m[tan] = 1;
    else
      m[tan]++;
  }
  for (auto i : m) v.push_back({i.first, i.second});
  sort(v.begin(), v.end(), compare);
  while (k > 0 && idx < v.size()) {
    k -= v[idx].second;
    idx++;
    answer++;
  }

  return answer;
}