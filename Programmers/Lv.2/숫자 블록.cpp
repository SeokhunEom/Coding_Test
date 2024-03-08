#include <cmath>
#include <string>
#include <vector>

using namespace std;

int func(int n) {
  if (n == 1) return 0;

  int max = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      max = i;
      if (n / i <= 10000000) return n / i;
    }
  }
  if (!max)
    return 1;
  else
    return max;
}

vector<int> solution(long long begin, long long end) {
  vector<int> answer;

  for (long long num = begin; num <= end; num++) answer.push_back(func(num));

  return answer;
}