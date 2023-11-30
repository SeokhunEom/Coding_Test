#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
  int answer = 0;

  int len = board.size();
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (i > 0 && j > 0 && board[i - 1][j - 1] == 1) continue;
      if (i > 0 && board[i - 1][j] == 1) continue;
      if (i > 0 && j < len - 1 && board[i - 1][j + 1] == 1) continue;

      if (j > 0 && board[i][j - 1] == 1) continue;
      if (board[i][j] == 1) continue;
      if (j < len - 1 && board[i][j + 1] == 1) continue;

      if (i < len - 1 && j > 0 && board[i + 1][j - 1] == 1) continue;
      if (i < len - 1 && board[i + 1][j] == 1) continue;
      if (i < len - 1 && j < len - 1 && board[i + 1][j + 1] == 1) continue;
      answer++;
    }
  }

  return answer;
}