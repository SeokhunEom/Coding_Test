#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
  vector<int> answer;

  answer.push_back(0);
  answer.push_back(0);
  for (string key : keyinput) {
    if (key == "up") {
      answer[1]++;
      if (answer[1] > board[1] / 2) answer[1]--;
    } else if (key == "down") {
      answer[1]--;
      if (answer[1] < -1 * (board[1] / 2)) answer[1]++;
    } else if (key == "left") {
      answer[0]--;
      if (answer[0] < -1 * (board[0] / 2)) answer[0]++;
    } else {
      answer[0]++;
      if (answer[0] > board[0] / 2) answer[0]--;
    }
  }

  return answer;
}