#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
  vector<int> answer;

  if (n > s) {
    answer.push_back(-1);
    return answer;
  }

  int base = s / n;
  int diff = s - base * n;
  for (int i = 0; i < n; i++) {
    if (i + diff >= n)
      answer.push_back(base + 1);
    else
      answer.push_back(base);
  }

  return answer;
}