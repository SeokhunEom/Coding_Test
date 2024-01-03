#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b);

vector<int> solution(int n, int m) {
  vector<int> answer;
  long long t = n * m;

  if (n > m)
    answer.push_back(gcd(n, m));
  else
    answer.push_back(gcd(m, n));
  answer.push_back(t / answer[0]);

  return answer;
}

int gcd(int a, int b) {
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}