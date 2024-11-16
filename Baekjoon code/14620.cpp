#include <climits>
#include <iostream>
using namespace std;

int N, sum, ans = INT_MAX;
bool flag;
int board[10][10];
int visited[10][10];
int temp[10][10];
pair<int, int> choice[3];

void func(int idx, int cnt) {
  if (cnt == 3) {
    flag = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        temp[i][j] = 0;
      }
    }

    for (int i = 0; i < 3; i++) {
      int x = choice[i].first;
      int y = choice[i].second;
      if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
        flag = false;
        break;
      }
      temp[x][y]++;
      temp[x - 1][y]++;
      temp[x + 1][y]++;
      temp[x][y - 1]++;
      temp[x][y + 1]++;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (temp[i][j] > 1) {
          flag = false;
          break;
        }
      }
    }

    if (flag) {
      sum = 0;
      for (int i = 0; i < 3; i++) {
        int x = choice[i].first;
        int y = choice[i].second;
        sum += board[x][y];
        sum += board[x - 1][y];
        sum += board[x + 1][y];
        sum += board[x][y - 1];
        sum += board[x][y + 1];
      }
      ans = min(ans, sum);
    }

    return;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j] == 0) {
        visited[i][j] = 1;
        choice[cnt] = {i, j};
        func(idx + 1, cnt + 1);
        visited[i][j] = 0;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  func(0, 0);
  cout << ans;

  return 0;
}