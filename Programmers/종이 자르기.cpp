#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
  int answer = 0;

  answer = (M - 1) + (N - 1) * M;

  return answer;
}