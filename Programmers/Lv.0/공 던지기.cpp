#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
  int answer = 1;

  for (int i = 1; i < k; i++) {
    answer += 2;
  }
  answer %= numbers.size();
  if (answer == 0) {
    answer = numbers.size();
  }

  return answer;
}