#include <string>
#include <vector>

using namespace std;

int solution(int num) {
  int answer = 0;
  unsigned long long t = num;

  while (t != 1) {
    if (t % 2 == 0)
      t /= 2;
    else
      t = t * 3 + 1;
    answer++;
    if (answer > 500) return -1;
  }

  return answer;
}