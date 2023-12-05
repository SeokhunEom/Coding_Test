#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;

bool compare(int a, int b) {
  if (abs(a - N) == abs(b - N)) {
    return a > b;
  }
  return abs(a - N) < abs(b - N);
}

vector<int> solution(vector<int> numlist, int n) {
  vector<int> answer = numlist;

  N = n;
  sort(answer.begin(), answer.end(), compare);

  return answer;
}