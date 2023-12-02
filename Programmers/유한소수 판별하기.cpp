#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
  int answer = 0;

  int min = a < b ? a : b;
  for (int i = 2; i <= min; i++) {
    if (a % i == 0 && b % i == 0) {
      a /= i;
      b /= i;
      i--;
    }
  }

  while (b % 2 == 0) {
    b /= 2;
  }
  while (b % 5 == 0) {
    b /= 5;
  }
  answer = b == 1 ? 1 : 2;

  return answer;
}