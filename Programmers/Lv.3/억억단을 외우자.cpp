#include <cmath>
#include <string>
#include <vector>

using namespace std;

int arr[5000001];
int dp[5000001];

vector<int> solution(int e, vector<int> starts) {
  vector<int> answer;
  int minStart = 5000000;

  for (int n : starts) minStart = min(minStart, n);

  for (int i = minStart; i <= e; i++) dp[i] = i;

  for (int i = 1; i <= e; i++) {
    for (int j = i; j <= e; j += i) arr[j]++;
  }

  for (int i = e - 1; i >= minStart; i--) {
    if (arr[i] >= arr[dp[i + 1]])
      dp[i] = i;
    else
      dp[i] = dp[i + 1];
  }

  for (int n : starts) answer.push_back(dp[n]);

  return answer;
}