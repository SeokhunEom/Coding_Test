#include <bits/stdc++.h>
using namespace std;

int n, t, ans;
vector<int> parent;
vector<int> item;
vector<int> colors;

int find(int x) {
  if (parent[x] != x) {
    parent[x] = find(parent[x]);
  }
  return parent[x];
}

void add(int x, int y) {
  int rootX = find(x);
  int rootY = find(y);

  if (rootX != rootY) {
    if (item[rootX] < item[rootY]) {
      parent[rootX] = rootY;
      item[rootY] += item[rootX];
    } else {
      parent[rootY] = rootX;
      item[rootX] += item[rootY];
    }
  }
}

void func(int n, const vector<int>& colors) {
  for (int i = 0; i < n; i++) {
    parent.push_back(i);
    item.push_back(1);
  }

  for (int color : colors) {
    int minSize = INT_MAX, minU = -1, minV = -1;
    int maxSize = -1, maxU = -1, maxV = -1;

    for (int u = 0; u < n; ++u) {
      for (int v = u + 1; v < n; ++v) {
        if (find(u) != find(v)) {
          int sizeU = item[find(u)];
          int sizeV = item[find(v)];

          if (color == 0) {
            if (sizeU + sizeV < minSize) {
              minSize = sizeU + sizeV;
              minU = u;
              minV = v;
            }
          } else {
            if (sizeU + sizeV > maxSize) {
              maxSize = sizeU + sizeV;
              maxU = u;
              maxV = v;
            }
          }
        }
      }
    }

    if (color == 0 && minU != -1 && minV != -1) {
      ans += item[find(minU)] * item[find(minV)];
      add(minU, minV);
    } else if (color == 1 && maxU != -1 && maxV != -1) {
      add(maxU, maxV);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> t;
    colors.push_back(t);
  }

  func(n, colors);
  cout << ans;

  return 0;
}
