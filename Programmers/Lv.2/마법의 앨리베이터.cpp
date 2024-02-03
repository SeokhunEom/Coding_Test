#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
  int answer = 0;

  while (storey) {
    int a = storey % 10;
    int b = (storey / 10) % 10;

    if (a > 5) {
      answer += 10 - a;
      storey += a;
    } else if (a == 5) {
      answer += a;
      storey += b >= 5 ? 5 : 0;
    } else {
      answer += a;
    }
    storey /= 10;
  }

  return answer;
}