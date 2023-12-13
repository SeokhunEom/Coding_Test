#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
  vector<int> answer(4);

  bool flag = true;
  int row = wallpaper.size();
  int col = wallpaper[0].length();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (wallpaper[i][j] == '#') {
        if (flag) {
          answer[0] = i;
          answer[1] = j;
          answer[2] = i + 1;
          answer[3] = j + 1;
          flag = false;
          continue;
        }
        if (i < answer[0]) {
          answer[0] = i;
        }
        if (j < answer[1]) {
          answer[1] = j;
        }
        if (i + 1 > answer[2]) {
          answer[2] = i + 1;
        }
        if (j + 1 > answer[3]) {
          answer[3] = j + 1;
        }
      }
    }
  }

  return answer;
}