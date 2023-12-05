#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
  int answer = 0;
  int coupon = chicken;

  while (coupon >= 10) {
    int order = coupon / 10;
    answer += order;
    coupon -= order * 10;
    coupon += order;
  }

  return answer;
}