#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
  int i = 0, j = 0, dir = 0;
  int n2 = n * n;
  int len = n2;
  vector<vector<int>> answer(n, vector<int>(n, 0));

  while (len--) {
    answer[i][j] = n2 - len;
    switch (dir) {
      case 0:
        j++;
        if (j == n - 1 || answer[i][j + 1] != 0) dir = 1;
        break;
      case 1:
        i++;
        if (i == n - 1 || answer[i + 1][j] != 0) dir = 2;
        break;
      case 2:
        j--;
        if (j == 0 || answer[i][j - 1] != 0) dir = 3;
        break;
      case 3:
        i--;
        if (i == 0 || answer[i - 1][j] != 0) dir = 0;
        break;
    }
  }

  return answer;
}