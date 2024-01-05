#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;
  int min = arr[0];
  int len = arr.size();

  if (len == 1) {
    answer.push_back(-1);
    return answer;
  }

  for (int a : arr) {
    if (a < min) min = a;
  }

  for (int a : arr) {
    if (a == min) continue;
    answer.push_back(a);
  }

  return answer;
}