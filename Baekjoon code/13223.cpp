#include <iostream>
using namespace std;

string str1, str2;
int t1, t2;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str1;
  cin >> str2;

  t1 = (str1[0] - '0') * 36000 + (str1[1] - '0') * 3600 +
       (str1[3] - '0') * 600 + (str1[4] - '0') * 60 + (str1[6] - '0') * 10 +
       (str1[7] - '0');
  t2 = (str2[0] - '0') * 36000 + (str2[1] - '0') * 3600 +
       (str2[3] - '0') * 600 + (str2[4] - '0') * 60 + (str2[6] - '0') * 10 +
       (str2[7] - '0');
  if (t1 >= t2) {
    t2 += 60 * 60 * 24;
  }

  t2 -= t1;

  cout << (t2 / 3600) / 10 << (t2 / 3600) % 10 << ":";
  cout << ((t2 % 3600) / 60) / 10 << ((t2 % 3600) / 60) % 10 << ":";
  cout << (t2 % 60) / 10 << (t2 % 60) % 10 << "\n";

  return 0;
}