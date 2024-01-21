#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
  vector<int> answer(2, 0);

  bool flag = false;
  int idx1 = 0, idx2 = 0;
  int sum = sequence[0];
  while (1) {
    if (sum == k) {
      if (idx2 - idx1 < answer[1] - answer[0] || flag == false) {
        answer[0] = idx1;
        answer[1] = idx2;
        flag = true;
      }
    }
    if (sum < k) {
      idx2++;
      if (idx2 > sequence.size()) break;
      sum += sequence[idx2];
    } else {
      sum -= sequence[idx1];
      idx1++;
    }
  }

  return answer;
}