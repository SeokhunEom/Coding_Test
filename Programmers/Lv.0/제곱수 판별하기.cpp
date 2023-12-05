#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  answer = sqrt(n) == int(sqrt(n)) ? 1 : 2;

  return answer;
}