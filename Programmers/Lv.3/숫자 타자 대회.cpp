#include <string>
#include <vector>

using namespace std;

int dist[10][10]{
    {1, 7, 6, 7, 5, 4, 5, 3, 2, 3}, {7, 1, 2, 4, 2, 3, 5, 4, 5, 6},
    {6, 2, 1, 2, 3, 2, 3, 5, 4, 5}, {7, 4, 2, 1, 5, 3, 2, 6, 5, 4},
    {5, 2, 3, 5, 1, 2, 4, 2, 3, 5}, {4, 3, 2, 3, 2, 1, 2, 3, 2, 3},
    {5, 5, 3, 2, 4, 2, 1, 5, 3, 2}, {3, 4, 5, 6, 2, 3, 5, 1, 2, 4},
    {2, 5, 4, 5, 3, 2, 3, 2, 1, 2}, {3, 6, 5, 4, 5, 3, 2, 4, 2, 1}};
int dp[100000][10][10];
string s;

int func(int idx, int left, int right) {
  if (idx == s.length()) return 0;

  int d = dp[idx][left][right];
  if (d != 0) return d;

  int num = s[idx] - '0';
  if (num == left || num == right) {
    dp[idx][left][right] = 1 + func(idx + 1, left, right);
    return dp[idx][left][right];
  }

  dp[idx][left][right] = min(func(idx + 1, num, right) + dist[left][num],
                             func(idx + 1, left, num) + dist[right][num]);
  return dp[idx][left][right];
}

int solution(string numbers) {
  int answer = 0;
  s = numbers;

  answer = func(0, 4, 6);
  return answer;
}