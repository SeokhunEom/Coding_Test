#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
  vector<int> count(1000, 0);
  int answer = -1, max = 0;

  for (int n : array) {
    count[n]++;
  }

  for (int i = 0; i < 1000; i++) {
    if (count[i] > max) {
      max = count[i];
    }
  }

  for (int i = 0; i < 1000; i++) {
    if (count[i] == max && answer == -1) {
      answer = i;
    } else if (count[i] == max && answer != -1) {
      return -1;
    }
  }

  return answer;
}