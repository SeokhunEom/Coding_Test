#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
  int answer = 0, dist, ansDist = 1000;

  sort(array.begin(), array.end());
  for (int num : array) {
    dist = n > num ? n - num : num - n;
    if (dist < ansDist) {
      answer = num;
      ansDist = dist;
    }
  }

  return answer;
}