#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
  vector<int> answer;
  vector<int> sum;

  for (vector<int> a : score) {
    sum.push_back(a[0] + a[1]);
  }
  for (int a : sum) {
    int rank = 1;
    for (int b : sum) {
      if (a < b) rank++;
    }
    answer.push_back(rank);
  }

  return answer;
}