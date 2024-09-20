#include <iostream>
using namespace std;

string s1, s2 = "";

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, s1);
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] >= 'a' && s1[i] <= 'z') {
      if (s1[i] + 13 > 'z') {
        s2 += s1[i] - 13;
      } else {
        s2 += s1[i] + 13;
      }
    } else if (s1[i] >= 'A' && s1[i] <= 'Z') {
      if (s1[i] + 13 > 'Z') {
        s2 += s1[i] - 13;
      } else {
        s2 += s1[i] + 13;
      }
    } else {
      s2 += s1[i];
    }
  }
  cout << s2;

  return 0;
}