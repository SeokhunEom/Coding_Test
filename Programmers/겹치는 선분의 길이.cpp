#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
  int answer = 0;

  for (int i = -100; i < 100; i++) {
    int overlap = 0;
    for (vector<int> line : lines) {
      if (line[0] <= i && line[1] >= i + 1) overlap++;
    }
    if (overlap >= 2) answer++;
  }

  return answer;
}