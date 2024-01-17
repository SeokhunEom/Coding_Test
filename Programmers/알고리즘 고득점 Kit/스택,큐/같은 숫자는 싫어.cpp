#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;

  int t = -1;
  for (int n : arr) {
    if (t == n) continue;
    answer.push_back(n);
    t = n;
  }

  return answer;
}