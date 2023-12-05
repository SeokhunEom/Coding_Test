#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
  int answer = 0;

  sort(numbers.begin(), numbers.end());
  int len = numbers.size();
  answer = numbers[len - 1] * numbers[len - 2];

  return answer;
}