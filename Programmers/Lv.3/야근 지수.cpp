#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
  long long answer = 0;

  sort(works.begin(), works.end(), greater<int>());
  int maxVal = works[0];
  int idx = 0;
  int len = works.size();

  for (int i = 0; i < n; i++) {
    works[idx++]--;
    if (idx >= len || works[idx] < maxVal) {
      idx = 0;
      maxVal = works[0];
    }
  }

  for (int work : works) answer += (work > 0 ? work * work : 0);

  return answer;
}