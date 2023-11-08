#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
  vector<vector<int>> answer = arr;

  int row = arr.size();
  int col = arr[0].size();

  if (row > col) {
    for (int i = 0; i < row; i++) {
      for (int j = col; j < row; j++) {
        answer[i].push_back(0);
      }
    }
  } else if (col > row) {
    for (int i = row; i < col; i++) {
      vector<int> v(col, 0);
      answer.push_back(v);
    }
  }

  return answer;
}