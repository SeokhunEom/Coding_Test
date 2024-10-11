#include <iostream>
using namespace std;

int H, W;
string s;
int board[101][101];
int visited[101][101];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      board[i][j] = s[j] == '.' ? 0 : 1;
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      visited[i][j] = -1;
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (board[i][j] == 1) {
        visited[i][j] = 0;
        for (int k = j + 1; k < W; k++) {
          visited[i][k] = visited[i][k - 1] + 1;
        }
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << visited[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}