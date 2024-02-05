#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int idx;
bool compare(vector<int> v1, vector<int> v2) {
  if (v1[idx - 1] == v2[idx - 1]) return v1[0] > v2[0];
  return v1[idx - 1] < v2[idx - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
  int answer = 0;
  vector<int> s;

  idx = col;
  sort(data.begin(), data.end(), compare);
  for (int i = row_begin; i <= row_end; i++) {
    s.push_back(0);
    for (int num : data[i - 1]) s[i - row_begin] += num % i;
  }

  answer = s[0];
  for (int i = 1; i < s.size(); i++) answer ^= s[i];

  return answer;
}
