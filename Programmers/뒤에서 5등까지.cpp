#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
  vector<int> answer = num_list;

  sort(answer.begin(), answer.end());
  answer = vector<int>(answer.begin(), answer.begin() + 5);

  return answer;
}