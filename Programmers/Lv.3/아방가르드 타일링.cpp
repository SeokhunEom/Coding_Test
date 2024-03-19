#include <string>
#include <vector>

using namespace std;

long long dp[100001];
long long sum[100001];

int solution(int n) {
  int answer = 0;

  dp[1] = 1;
  dp[2] = 3;
  dp[3] = 10;
  dp[4] = 23;
  dp[5] = 62;
  dp[6] = 170;
  sum[1] = 1;
  sum[2] = 3;
  sum[3] = 11;
  sum[4] = 24;
  sum[5] = 65;
  sum[6] = 181;

  for (int i = 7; i <= n; i++) {
    dp[i] = dp[i - 1];
    dp[i] += dp[i - 2] * 2;
    dp[i] += dp[i - 3] * 5;
    dp[i] += sum[i - 4] * 2;
    dp[i] += sum[i - 5] * 2;
    dp[i] += sum[i - 6] * 4;
    dp[i] %= 1000000007;
    sum[i] = dp[i] + sum[i - 3];
    sum[i] %= 1000000007;
  }
  answer = dp[n];

  return answer;
}