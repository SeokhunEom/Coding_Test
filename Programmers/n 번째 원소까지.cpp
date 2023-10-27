#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
  vector<int> answer;

  answer = vector<int>(num_list.begin(), num_list.begin() + n);

  return answer;
}