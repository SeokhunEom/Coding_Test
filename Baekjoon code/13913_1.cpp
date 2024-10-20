#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int visited[100001][2];
queue<int> q;
vector<int> path;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 100001; i++) {
    visited[i][0] = -1;
    visited[i][1] = -1;
  }
  cin >> N >> K;
  q.push(N);
  visited[N][0] = 0;
  visited[N][1] = N;

  if (N == K) {
    cout << 0 << '\n';
    cout << N << '\n';
    return 0;
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == K) {
      while (cur != visited[cur][1]) {
        path.push_back(cur);
        cur = visited[cur][1];
      }
      path.push_back(N);
      break;
    }

    if (cur - 1 >= 0 && visited[cur - 1][0] == -1) {
      q.push(cur - 1);
      visited[cur - 1][0] = visited[cur][0] + 1;
      visited[cur - 1][1] = cur;
    }
    if (cur + 1 <= 100000 && visited[cur + 1][0] == -1) {
      q.push(cur + 1);
      visited[cur + 1][0] = visited[cur][0] + 1;
      visited[cur + 1][1] = cur;
    }
    if (cur * 2 <= 100000 && visited[cur * 2][0] == -1) {
      q.push(cur * 2);
      visited[cur * 2][0] = visited[cur][0] + 1;
      visited[cur * 2][1] = cur;
    }
  }

  cout << visited[K][0] << '\n';
  for (int i = 0; i < path.size(); i++) {
    cout << path[path.size() - 1 - i] << ' ';
  }

  return 0;
}