#include <climits>
#include <string>
#include <vector>

using namespace std;

int dp[201][201];

int solution(vector<vector<int>> matrix_sizes) {
  int answer = 0;

  int n = matrix_sizes.size();

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      int k = i + j;
      dp[j][k] = INT_MAX;
      for (int l = j; l < k; l++) {
        int temp = dp[j][l] + dp[l + 1][k] +
                   matrix_sizes[j][0] * matrix_sizes[l][1] * matrix_sizes[k][1];
        dp[j][k] = min(dp[j][k], temp);
      }
    }
  }

  answer = dp[0][n - 1];

  return answer;
}