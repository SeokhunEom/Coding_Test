#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
  string answer = "";
  int start = numLog[0], before = numLog[0], diff;

  for (int n : numLog) {
    diff = n - before;
    before = n;
    if (diff == 1) {
      answer.push_back('w');
    } else if (diff == -1) {
      answer.push_back('s');
    } else if (diff == 10) {
      answer.push_back('d');
    } else if (diff == -10) {
      answer.push_back('a');
    }
  }

  return answer;
}