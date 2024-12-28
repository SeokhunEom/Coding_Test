#include <iostream>
using namespace std;

string str1, str2;
int ans = 0;
bool flag;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, str1);
  getline(cin, str2);

  for (int i = 0; i < str1.length(); i++) {
    flag = true;
    for (int j = 0; j < str2.length(); j++) {
      if (str1[i + j] != str2[j]) {
        flag = false;
        break;
      }
    }

    if (flag) {
      ans++;
      i += str2.length() - 1;
    }
  }

  cout << ans;

  return 0;
}