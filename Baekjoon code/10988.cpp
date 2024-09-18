#include <iostream>
#include <algorithm>
using namespace std;

string s1, s2;
bool flag = true;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s1;
  s2 = s1;
  reverse(s2.begin(), s2.end());
  for(int i = 0; i < s1.size(); i++) {
    if(s1[i] != s2[i]) {
      flag = false;
      break;
    }
  }
  cout << (flag ? 1 : 0);

  return 0;
}