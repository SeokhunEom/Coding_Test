#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
  vector<int> answer;

  answer = num_list;
  answer.push_back(answer[answer.size() - 1] > answer[answer.size() - 2]
                       ? answer[answer.size() - 1] - answer[answer.size() - 2]
                       : answer[answer.size() - 1] * 2);

  return answer;
}