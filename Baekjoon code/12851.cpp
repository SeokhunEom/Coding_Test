#include <climits>
#include <iostream>
#include <queue>
using namespace std;

int N, K, ans1 = INT_MAX, ans2 = 0;
bool first = true;
queue<pair<int, int>> q;
int visited[100001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  q.push({N, 0});
  visited[N] = 1;

  while (!q.empty()) {
    int cur = q.front().first;
    int cnt = q.front().second;
    q.pop();
    visited[cur] = 1;

    if (!first && ans1 == cnt && cur == K) {
      ans2++;
    }
    if (first && cur == K) {
      ans1 = cnt;
      first = false;
      ans2++;
    }

    if (cur + 1 < 100001 && cur + 1 >= 0 && visited[cur + 1] == 0) {
      q.push(make_pair(cur + 1, cnt + 1));
    }
    if (cur - 1 < 100001 && cur - 1 >= 0 && visited[cur - 1] == 0) {
      q.push(make_pair(cur - 1, cnt + 1));
    }
    if (cur * 2 < 100001 && cur * 2 >= 0 && visited[cur * 2] == 0) {
      q.push(make_pair(cur * 2, cnt + 1));
    }
  }
  cout << ans1 << '\n' << ans2;

  return 0;
}