#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector<int> tree[100001];
int arr[100001];
bool vis[100001];
queue<int> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i < N; i++) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int child : tree[cur]) {
      if (!vis[child]) {
        arr[child] = cur;
        vis[child] = true;
        q.push(child);
      }
    }
  }

  for (int i = 2; i <= N; i++) cout << arr[i] << '\n';

  return 0;
}
