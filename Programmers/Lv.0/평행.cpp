#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
  int answer = 0;
  double a1, a2, b1, b2, c1, c2;

  a1 = (double)(dots[0][1] - dots[1][1]) / (dots[0][0] - dots[1][0]);
  a2 = (double)(dots[2][1] - dots[3][1]) / (dots[2][0] - dots[3][0]);
  b1 = (double)(dots[0][1] - dots[2][1]) / (dots[0][0] - dots[2][0]);
  b2 = (double)(dots[1][1] - dots[3][1]) / (dots[1][0] - dots[3][0]);
  c1 = (double)(dots[0][1] - dots[3][1]) / (dots[0][0] - dots[3][0]);
  c2 = (double)(dots[1][1] - dots[2][1]) / (dots[1][0] - dots[2][0]);

  if (a1 == a2 || b1 == b2 || c1 == c2) answer = 1;

  return answer;
}