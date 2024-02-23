#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2) {
  vector<vector<int>> answer;

  int m = arr1.size();
  int n = arr1[0].size();
  int p = arr2[0].size();

  for (int i = 0; i < m; i++) {
    vector<int> v;
    for (int j = 0; j < p; j++) {
      int sum = 0;
      for (int k = 0; k < n; k++) sum += arr1[i][k] * arr2[k][j];
      v.push_back(sum);
    }
    answer.push_back(v);
  }

  return answer;
}