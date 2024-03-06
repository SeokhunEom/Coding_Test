#include <string>
#include <vector>

using namespace std;

long long fact(int n) {
  long long ret = 1;
  for (int i = 1; i <= n; i++) ret *= i;
  return ret;
}

vector<int> solution(int n, long long k) {
  vector<int> answer;
  vector<int> num;
  long long cur = k;
  int cnt = 1;

  for (int i = 1; i <= 20; i++) num.push_back(i);

  while (cnt != n) {
    long long temp = fact(n - cnt);
    int idx = (cur - 1) / temp;
    answer.push_back(num[idx]);
    num.erase(num.begin() + idx);
    cnt++;
    cur %= temp;
    if (cur == 0) cur = temp;
  }
  answer.push_back(num[0]);

  return answer;
}