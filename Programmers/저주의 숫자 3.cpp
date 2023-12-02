#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  for (int i = 0; i < n; i++) {
    if (answer % 3 == 0 || to_string(answer).find('3') != -1) i--;
    answer++;
  }
  answer--;

  return answer;
}