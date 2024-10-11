#include <iostream>
#include <vector>
using namespace std;

int T;
string s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    vector<char> v;
    bool flag = true;
    cin >> s;
    for (char c : s) {
      if (c == '(') {
        v.push_back(c);
      } else {
        if (v.empty()) {
          flag = false;
          break;
        }
        v.pop_back();
      }
    }
    if (!v.empty()) {
      flag = false;
    }

    if (flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}