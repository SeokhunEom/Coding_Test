#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value = -1;
  vector<int> child;
};

int n, u, v, max_depth;
vector<int> edge[100001];
vector<int> depth[100001];
Node tree[100001];

void make_tree() {
  queue<int> q, temp;
  q.push(1);
  tree[1].value = 1;
  depth[1].push_back(1);

  for (int i = 2; i <= n; i++) {
    while (!q.empty()) {
      int front = q.front();
      q.pop();

      for (int j = 0; j < edge[front].size(); j++) {
        int next = edge[front][j];
        if (tree[next].value != -1) continue;
        temp.push(next);
        tree[front].child.push_back(next);
        tree[next].value = next;
        depth[i].push_back(next);
      }
    }
    if (temp.empty()) {
      max_depth = i - 1;
      return;
    }
    q.swap(temp);
  }
}

void run_tree() {
  for (int i = max_depth; i >= 1; i--) {
    for (int j = 0; j < depth[i].size(); j++) {
      int index = depth[i][j];
      if (tree[index].child.empty()) continue;
      int min_value = tree[tree[index].child[0]].value;
      for (int k = 0; k < tree[index].child.size(); k++) {
        int t = tree[index].child[k];
        min_value = min(min_value, tree[t].value);
      }
      tree[index].value -= min_value;
    }
  }
}

int main(void) {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  make_tree();
  run_tree();

  for (int i = 1; i <= n; i++) {
    cout << (tree[i].value >= 0 ? "1" : "0") << "\n";
  }

  return 0;
}