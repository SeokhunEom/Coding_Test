#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void func(int from, int to, int n) {
  vector<int> v;
  v.push_back(from);
  v.push_back(to);
  if (n == 1) {
    answer.push_back(v);
    return;
  }
  int mid = 6 - from - to;
  func(from, mid, n - 1);
  answer.push_back(v);
  func(mid, to, n - 1);
}

vector<vector<int>> solution(int n) {
  func(1, 3, n);

  return answer;
}