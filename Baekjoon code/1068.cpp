#include <iostream>
#include <queue>
using namespace std;

int N, target, root, cnt;
int arr[50];
int adj[50][50];
int visited[50];
queue<int> q;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] == -1) root = i;
  }
  cin >> target;

  for (int i = 0; i < N; i++) {
    if (arr[i] == -1) continue;
    adj[arr[i]][i] = 1;
    adj[i][arr[i]] = 1;
  }
  for (int i = 0; i < N; i++) {
    adj[i][target] = 0;
    adj[target][i] = 0;
  }

  if (target == root) {
    cout << 0;
    return 0;
  }

  q.push(root);
  visited[root] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    bool flag = false;
    for (int i = 0; i < N; i++) {
      if (adj[cur][i] == 1 && visited[i] == 0) {
        q.push(i);
        visited[i] = 1;
        flag = true;
      }
    }

    if (flag == false) {
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}