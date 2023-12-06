#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int idx;
bool compare(vector<int> a, vector<int> b) { return a[idx] < b[idx]; }

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext,
                             string sort_by) {
  vector<vector<int>> answer;

  idx = ext == "code" ? 0 : ext == "date" ? 1 : ext == "maximum" ? 2 : 3;
  for (vector<int> d : data) {
    if (d[idx] < val_ext) answer.push_back(d);
  }
  idx = sort_by == "code"      ? 0
        : sort_by == "date"    ? 1
        : sort_by == "maximum" ? 2
                               : 3;
  sort(answer.begin(), answer.end(), compare);

  return answer;
}