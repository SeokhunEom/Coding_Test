#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
  int answer = 0;
  int max1 = 0;
  int max2 = 0;

  for (vector<int> size : sizes) {
    if (size[0] > size[1]) {
      max1 = max1 > size[0] ? max1 : size[0];
      max2 = max2 > size[1] ? max2 : size[1];
    } else {
      max1 = max1 > size[1] ? max1 : size[1];
      max2 = max2 > size[0] ? max2 : size[0];
    }
  }

  answer = max1 * max2;

  return answer;
}