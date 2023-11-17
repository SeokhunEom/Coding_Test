#include <string>
#include <vector>

using namespace std;

__int128 factorial(int n);

__int128 solution(int balls, int share) {
  __int128 answer = 0;

  answer = factorial(balls) / (factorial(balls - share) * factorial(share));

  return answer;
}

__int128 factorial(int n) {
  __int128 res = 1;

  for (int i = 2; i <= n; i++) {
    res *= i;
  }

  return res;
}