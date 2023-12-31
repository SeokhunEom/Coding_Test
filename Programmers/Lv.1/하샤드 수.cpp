#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
  bool answer = true;

  if (x % ((x % 10) + ((x / 10) % 10) + ((x / 100) % 10) + ((x / 1000) % 10) +
           ((x / 10000) % 10)) !=
      0)
    answer = false;

  return answer;
}