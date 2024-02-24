#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool isPrime(long long num) {
  if (num < 2) return false;
  for (long long i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

int solution(int n, int k) {
  int answer = 0;
  string numStr = "";

  while (n != 0) {
    numStr = to_string(n % k) + numStr;
    n = n / k;
  }

  vector<long long> numArr;
  int start = 0;
  int end = numStr.find("0");
  while (end != string::npos) {
    string token = numStr.substr(start, end - start);
    if (!token.empty()) {
      numArr.push_back(stoll(token));
    }
    start = end + 1;
    end = numStr.find("0", start);
  }
  string lastToken = numStr.substr(start);
  if (!lastToken.empty()) {
    numArr.push_back(stoll(lastToken));
  }

  for (long long num : numArr) {
    if (isPrime(num)) answer++;
  }

  return answer;
}
