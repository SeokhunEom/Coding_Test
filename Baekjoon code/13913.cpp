#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[100001];
int path[100001];
vector<int> v;
queue<int> q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  fill(arr, arr + 100001, -1);
  fill(path, path + 100001, -1);

  q.push(N);
  arr[N] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (cur == K) {
      cout << arr[cur] << '\n';
      while (cur != -1) {
        v.push_back(cur);
        cur = path[cur];
      }
      while (!v.empty()) {
        cout << v.back() << ' ';
        v.pop_back();
      }
      break;
    }

    if (cur - 1 >= 0 && arr[cur - 1] == -1) {
      arr[cur - 1] = arr[cur] + 1;
      path[cur - 1] = cur;
      q.push(cur - 1);
    }
    if (cur + 1 <= 100000 && arr[cur + 1] == -1) {
      arr[cur + 1] = arr[cur] + 1;
      path[cur + 1] = cur;
      q.push(cur + 1);
    }
    if (cur * 2 <= 100000 && arr[cur * 2] == -1) {
      arr[cur * 2] = arr[cur] + 1;
      path[cur * 2] = cur;
      q.push(cur * 2);
    }
  }

  return 0;
}
