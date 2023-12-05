#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
  int answer = 0;

  int t = 0;
  if (common[2] - common[1] == common[1] - common[0]) {
    t = common[2] - common[1];
    answer = common[common.size() - 1] + t;
  } else {
    t = common[2] / common[1];
    answer = common[common.size() - 1] * t;
  }

  return answer;
}