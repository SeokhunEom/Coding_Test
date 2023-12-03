#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
  string answer = "";

  reverse(bin1.begin(), bin1.end());
  reverse(bin2.begin(), bin2.end());
  int n = bin1.size() > bin2.size() ? bin1.size() - bin2.size()
                                    : bin2.size() - bin1.size();
  if (bin1.size() > bin2.size()) {
    for (int i = 0; i < n; i++) {
      bin2 += '0';
    }
  } else {
    for (int i = 0; i < n; i++) {
      bin1 += '0';
    }
  }

  int len = bin1.size();
  int carry = 0;
  for (int i = 0; i < len; i++) {
    n = (bin1[i] - '0') + (bin2[i] - '0') + carry;
    carry = n / 2;
    answer += to_string(n % 2);
  }
  if (carry == 1) {
    answer += to_string(carry);
  }
  reverse(answer.begin(), answer.end());

  return answer;
}