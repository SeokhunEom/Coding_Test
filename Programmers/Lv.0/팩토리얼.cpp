#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  long long p = 1;

  for (int i = 1;; i++) {
    p *= i;
    if (p > n) {
      answer = i - 1;
      break;
    }
  }

  return answer;
}