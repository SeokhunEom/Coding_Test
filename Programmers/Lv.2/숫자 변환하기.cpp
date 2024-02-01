#include <climits>
#include <string>
#include <vector>

using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {
  int answer = 0;

  for (int i = x; i <= y; i++) dp[i] = INT_MAX;
  dp[x] = 0;
  for (int i = x; i <= y; i++) {
    if (dp[i] == INT_MAX) continue;
    if (i + n <= 1000000) dp[i + n] = min(dp[i + n], dp[i] + 1);
    if (i * 2 <= 1000000) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
    if (i * 3 <= 1000000) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
  }
  answer = dp[y] == INT_MAX ? -1 : dp[y];

  return answer;
}