#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string a, string b) {
  string answer = "";

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int lenA = a.length();
  int lenB = b.length();
  if (lenA < lenB) {
    for (int i = lenA; i < lenB; i++) {
      a += '0';
    }
    lenA = lenB;
  } else {
    for (int i = lenB; i < lenA; i++) {
      b += '0';
    }
    lenB = lenA;
  }

  int carry = 0;
  for (int i = 0; i < lenA; i++) {
    int sum = (a[i] - '0') + (b[i] - '0') + carry;
    answer += (sum % 10) + '0';
    carry = sum / 10;
  }
  if (carry != 0) {
    answer += carry + '0';
  }

  reverse(answer.begin(), answer.end());

  return answer;
}