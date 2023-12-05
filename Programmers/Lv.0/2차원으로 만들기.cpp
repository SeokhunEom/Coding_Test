#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
  vector<vector<int>> answer;

  int len = 0;
  vector<int> temp;
  for (int num : num_list) {
    temp.push_back(num);
    len++;
    if (len == n) {
      answer.push_back(temp);
      temp.clear();
      len = 0;
    }
  }

  return answer;
}