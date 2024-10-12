#include <iostream>
#include <vector>
using namespace std;

int N, M, ans = 100000000, v_size;
int arr[51][51];
vector<pair<int, int>> v;
int choose[14];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void func(int depth, int idx);
int func2();

void func(int depth, int idx) {
  if (depth == M) {
    int ret = func2();
    ans = min(ans, ret);
    return;
  }

  for (int i = idx; i < v_size; i++) {
    choose[depth] = i;
    func(depth + 1, i + 1);
  }
}

int func2() {
  int ret = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (arr[i][j] != 1) continue;
      int min_dist = 100000000;
      for (int k = 0; k < M; k++) {
        int dist = abs(v[choose[k]].first - i) + abs(v[choose[k]].second - j);
        min_dist = min(min_dist, dist);
      }
      ret += min_dist;
    }
  }

  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) {
        v.push_back({i, j});
        v_size++;
      }
    }
  }

  func(0, 0);
  cout << ans;

  return 0;
}