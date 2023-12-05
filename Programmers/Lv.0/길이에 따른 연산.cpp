#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
  int answer = 0;

  if (num_list.size() <= 10) {
    answer = 1;
    for (int num : num_list) {
      answer *= num;
    }
  } else {
    for (int num : num_list) {
      answer += num;
    }
  }

  return answer;
}