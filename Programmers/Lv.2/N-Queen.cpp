#include <cmath>
#include <string>
#include <vector>

using namespace std;

void dfs(int col, int& answer, vector<int>& board) {
  if (board.size() == col)
    answer++;
  else {
    for (int i = 0; i < board.size(); i++) {
      bool flag = true;
      board[col] = i;

      for (int u = 0; u < col; u++) {
        if (board[col] == board[u] ||
            abs(board[col] - board[u]) == abs(col - u)) {
          flag = false;
          break;
        }
      }
      if (flag) dfs(col + 1, answer, board);
    }
  }
}

int solution(int n) {
  int answer = 0;
  vector<int> board(n, 0);
  dfs(0, answer, board);

  return answer;
}