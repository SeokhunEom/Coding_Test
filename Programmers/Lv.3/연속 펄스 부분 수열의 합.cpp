#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
  long long answer = (sequence[0] >= 0 ? sequence[0] : sequence[0] * -1);
  long long sum = 0;
  vector<int> v1, v2;

  for (int i = 0; i < sequence.size(); i++) {
    if (i % 2 == 0) {
      v1.push_back(sequence[i]);
      v2.push_back(sequence[i] * -1);
    } else {
      v1.push_back(sequence[i] * -1);
      v2.push_back(sequence[i]);
    }
  }

  for (int n : v1) {
    sum += n;
    if (sum < 0) sum = 0;
    if (sum > answer) answer = sum;
  }
  sum = 0;
  for (int n : v2) {
    sum += n;
    if (sum < 0) sum = 0;
    if (sum > answer) answer = sum;
  }

  return answer;
}