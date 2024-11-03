#include <iostream>
#include <vector>
using namespace std;

int N, M, a, b, c, ans;
vector<int> v[1001];
int arr[1001][1001];
int visited[1001];

void func(int start, int depth) {
  if (start == b) {
    ans = depth;
    return;
  }
  if (visited[start] == 1) return;
  visited[start] = 1;
  for (int i = 0; i < v[start].size(); i++) {
    int next = v[start][i];
    if (arr[start][next] != 0) {
      func(next, depth + arr[start][next]);
    } else if (arr[start][next] == 0 && arr[next][start] != 0) {
      func(next, depth + arr[next][start]);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b >> c;
    v[a].push_back(b);
    v[b].push_back(a);
    arr[a][b] = c;
    arr[b][a] = c;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 1001; j++) {
      visited[j] = 0;
    }
    cin >> a >> b;
    func(a, 0);
    cout << ans << "\n";
  }

  return 0;
}