#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
  int answer = 0;
  int na, nb;

  if (b - 10 < 0) {
    nb = 10;
  } else if (b - 100 < 0) {
    nb = 100;
  } else if (b - 1000 < 0) {
    nb = 1000;
  } else {
    nb = 10000;
  }

  if (a - 10 < 0) {
    na = 10;
  } else if (a - 100 < 0) {
    na = 100;
  } else if (a - 1000 < 0) {
    na = 1000;
  } else {
    na = 10000;
  }

  answer = a * nb + b;
  if (b * na + a > answer) {
    answer = b * na + a;
  }

  return answer;
}