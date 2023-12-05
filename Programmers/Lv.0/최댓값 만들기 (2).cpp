#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
  int answer = numbers[0] * numbers[1];

  int len = numbers.size();
  for (int i = 0; i < len; i++) {
    for (int j = 1; j < len; j++) {
      if (i == j) continue;
      if (numbers[i] * numbers[j] > answer) {
        answer = numbers[i] * numbers[j];
      }
    }
  }

  return answer;
}