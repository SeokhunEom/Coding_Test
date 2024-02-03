#include <string>
#include <vector>

using namespace std;

long long func(long long n, long long i) {
  if (i % 5 == 2) return 0;
  if (n == 1) return 1;
  return func(n - 1, i / 5);
}

int solution(int n, long long l, long long r) {
  int answer = 0;

  for (long long i = l - 1; i < r; i++) answer += func(n, i);

  return answer;
}