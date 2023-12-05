#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  for (int i = 6;; i += 6) {
    if (i % n == 0) {
      answer = i / 6;
      break;
    }
  }

  return answer;
}