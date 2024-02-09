#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(int k, int d) {
  long long answer = 0;

  for (int i = 0; i <= d; i += k) {
    answer += 1 + (floor(sqrt((long long)d * d - (long long)i * i)) / k);
  }

  return answer;
}