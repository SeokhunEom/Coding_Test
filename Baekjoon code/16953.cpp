#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

long long A, B;
unordered_map<long long, int> dp;
queue<long long> q;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;
  dp[A] = 1;
  q.push(A);

  while (!q.empty()) {
    long long cur = q.front();
    q.pop();

    if (cur == B) {
      cout << dp[cur];
      return 0;
    }

    if (cur * 2 <= B && !dp.count(cur * 2)) {
      dp[cur * 2] = dp[cur] + 1;
      q.push(cur * 2);
    }
    if (cur * 10 + 1 <= B && !dp.count(cur * 10 + 1)) {
      dp[cur * 10 + 1] = dp[cur] + 1;
      q.push(cur * 10 + 1);
    }
  }

  cout << -1;

  return 0;
}