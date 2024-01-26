#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
  int condition[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                         {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

  int a = 0, b = 0;
  for (string s : board) {
    for (char c : s) {
      if (c == 'O') a++;
      if (c == 'X') b++;
    }
  }
  if (a != b && a != b + 1) return 0;

  bool win1 = false;
  bool win2 = false;
  for (int* arr : condition) {
    char c1 = board[arr[0] / 3][arr[0] % 3];
    char c2 = board[arr[1] / 3][arr[1] % 3];
    char c3 = board[arr[2] / 3][arr[2] % 3];
    if (c1 == c2 && c2 == c3) {
      if (c1 == 'O') win1 = true;
      if (c1 == 'X') win2 = true;
    }
  }
  if (win1 == true && win2 == true) return 0;
  if (win1 == true && a == b) return 0;
  if (win2 == true && a != b) return 0;

  return 1;
}