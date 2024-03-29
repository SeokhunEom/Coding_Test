#include <string>
#include <vector>

using namespace std;

int dp[100000][2];

vector<int> solution(int target) {
  vector<int> answer(2, 0);

  for (int i = 1; i <= 20; i++) dp[i * 3][0] = 1;
  for (int i = 1; i <= 20; i++) dp[i * 3][1] = 0;
  for (int i = 1; i <= 20; i++) dp[i * 2][0] = 1;
  for (int i = 1; i <= 20; i++) dp[i * 2][1] = 0;
  for (int i = 1; i <= 20; i++) dp[i][0] = 1;
  for (int i = 1; i <= 20; i++) dp[i][1] = 1;
  dp[50][0] = 1;
  dp[50][1] = 1;

  for (int i = 21; i <= 70; i++) {
    if (dp[i][0] != 0) continue;
    dp[i][0] = 2;
    if (i >= 41 && i < 50)
      dp[i][1] = 1;
    else
      dp[i][1] = 2;
  }

  for (int i = 71; i <= target; i++) {
    if (dp[i - 60][0] == dp[i - 50][0]) {
      dp[i][0] = dp[i - 50][0] + 1;
      dp[i][1] = max(dp[i - 60][1], dp[i - 50][1] + 1);
    } else if (dp[i - 60][0] < dp[i - 50][0]) {
      dp[i][0] = dp[i - 60][0] + 1;
      dp[i][1] = dp[i - 60][1];
    } else {
      dp[i][0] = dp[i - 50][0] + 1;
      dp[i][1] = dp[i - 50][1] + 1;
    }
  }

  answer[0] = dp[target][0];
  answer[1] = dp[target][1];

  return answer;
}