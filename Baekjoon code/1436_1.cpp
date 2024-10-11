#include <iostream>
using namespace std;

int N, num = 665;

bool func(int num) {
  bool flag = false;

  string s = to_string(num);
  for (int i = 2; i < s.size(); i++) {
    if (s[i - 2] == '6' && s[i - 1] == '6' && s[i] == '6') {
      flag = true;
      break;
    }
  }

  return flag;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N;) {
    num++;
    if (func(num)) {
      i++;
    }
  }
  cout << num;

  return 0;
}