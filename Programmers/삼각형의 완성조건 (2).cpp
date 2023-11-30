#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
  int answer = 0;

  int min = sides[0] < sides[1] ? sides[0] : sides[1];
  answer += 2 * min - 1;

  return answer;
}