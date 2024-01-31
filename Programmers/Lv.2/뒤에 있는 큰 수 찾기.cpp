#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
  vector<int> answer(numbers.size(), -1);
  vector<int> v;

  for (int i = numbers.size() - 1; i >= 0; i--) {
    while (1) {
      if (v.empty()) {
        answer[i] = -1;
        break;
      }
      if (v.back() > numbers[i]) {
        answer[i] = v.back();
        break;
      }
      v.pop_back();
    }
    v.push_back(numbers[i]);
  }

  return answer;
}