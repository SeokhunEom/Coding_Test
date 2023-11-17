#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
  int answer = 0;

  answer += hp / 5;
  if (hp % 5 == 4) {
    answer += 2;
  } else if (hp % 5 == 3) {
    answer += 1;
  } else {
    answer += hp % 5;
  }

  return answer;
}