#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> scores) {
  int answer = scores.size() + 1;
  int sum = scores[0][0] + scores[0][1];
  int size = scores.size();

  for (vector<int> v : scores) {
    if (v[0] > scores[0][0] && v[1] > scores[0][1]) return -1;
  }

  sort(scores.begin() + 1, scores.end());

  for (int i = 1; i < size; i++) {
    if (sum >= scores[i][0] + scores[i][1]) continue;
    for (int j = i + 1; j < size; j++) {
      if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]) {
        answer--;
        break;
      }
    }
  }

  for (vector<int> v : scores) {
    if (sum >= v[0] + v[1]) answer--;
  }

  return answer;
}