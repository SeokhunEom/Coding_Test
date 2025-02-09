#include <iostream>
#include <vector>
using namespace std;

int T, N, B;
bool flag;

bool isPalindrome(vector<int>& digits) {
  int left = 0, right = digits.size() - 1;

  while (left < right) {
    if (digits[left] != digits[right]) return false;
    left++;
    right--;
  }

  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    flag = false;
    cin >> N;

    for (int b = 2; b <= 64; b++) {
      int temp = N;
      vector<int> digits;

      while (temp > 0) {
        digits.push_back(temp % b);
        temp /= b;
      }
      if (isPalindrome(digits)) {
        flag = true;
        break;
      }
    }

    if (flag) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }

  return 0;
}