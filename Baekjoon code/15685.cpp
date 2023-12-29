#include <bits/stdc++.h>
using namespace std;

int N, x, y, d, g, ans;
int board[101][101];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> d >> g;

    vector<int> v;
    v.push_back(d);
    board[y][x] = 1;

    for (int j = 0; j < g; j++) {
      for (int k = v.size() - 1; k >= 0; k--) {
        v.push_back((v[k] + 1) % 4);
      }
    }

    for (int j = 0; j < v.size(); j++) {
      if (v[j] == 0)
        x++;
      else if (v[j] == 1)
        y--;
      else if (v[j] == 2)
        x--;
      else
        y++;
      board[y][x] = 1;
    }
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (board[i][j] == 0) continue;
      if (board[i][j + 1] == 1 && board[i + 1][j] == 1 &&
          board[i + 1][j + 1] == 1) {
        ans++;
      }
    }
  }
  cout << ans;

  return 0;
}
