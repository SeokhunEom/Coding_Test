#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
  vector<int> answer = num_list;

  reverse(answer.begin(), answer.end());

  return answer;
}