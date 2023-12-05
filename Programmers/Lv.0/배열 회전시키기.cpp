#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
  vector<int> answer;

  int len = numbers.size();
  if (direction == "left") {
    for (int i = 1; i < len; i++) {
      answer.push_back(numbers[i]);
    }
    answer.push_back(numbers[0]);
  } else {
    answer.push_back(numbers[len - 1]);
    for (int i = 0; i < len - 1; i++) {
      answer.push_back(numbers[i]);
    }
  }

  return answer;
}