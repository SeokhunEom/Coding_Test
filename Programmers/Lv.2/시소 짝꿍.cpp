#include <string>
#include <vector>

using namespace std;

int count[1001];

long long solution(vector<int> weights) {
  long long answer = 0;

  for (int w : weights) count[w]++;
  for (int w : weights) {
    answer += (count[w] - 1);
    if (w % 3 == 0) answer += (count[w * 2 / 3]);
    if (w % 2 == 0) answer += (count[w / 2]);
    if (w % 2 == 0 && w * 3 / 2 <= 1000) answer += (count[w * 3 / 2]);
    if (w % 4 == 0) answer += (count[w * 3 / 4]);
    if (w * 2 <= 1000) answer += (count[w * 2]);
    if (w % 3 == 0 && w * 4 / 3 <= 1000) answer += (count[w * 4 / 3]);
  }

  return answer / 2;
}