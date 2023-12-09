#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
  vector<int> answer(2);

  int H = park.size();
  int W = park[0].length();
  int flag = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (park[i][j] == 'S') {
        answer[0] = i;
        answer[1] = j;
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
  }

  for (string route : routes) {
    char dir = route[0];
    int n = route[2] - '0';

    if (dir == 'N') {
      if (answer[0] - n < 0) continue;
      flag = 0;
      for (int i = 1; i <= n; i++) {
        if (park[answer[0] - i][answer[1]] == 'X') {
          flag = 1;
          break;
        }
      }
      if (flag == 1) continue;
      answer[0] -= n;
    } else if (dir == 'S') {
      if (answer[0] + n >= H) continue;
      int flag = 0;
      for (int i = 1; i <= n; i++) {
        if (park[answer[0] + i][answer[1]] == 'X') {
          flag = 1;
          break;
        }
      }
      if (flag == 1) continue;
      answer[0] += n;
    } else if (dir == 'W') {
      if (answer[1] - n < 0) continue;
      int flag = 0;
      for (int i = 1; i <= n; i++) {
        if (park[answer[0]][answer[1] - i] == 'X') {
          flag = 1;
          break;
        }
      }
      if (flag == 1) continue;
      answer[1] -= n;
    } else if (dir == 'E') {
      if (answer[1] + n >= W) continue;
      int flag = 0;
      for (int i = 1; i <= n; i++) {
        if (park[answer[0]][answer[1] + i] == 'X') {
          flag = 1;
          break;
        }
      }
      if (flag == 1) continue;
      answer[1] += n;
    }
  }

  return answer;
}