#include <iostream>
#include <vector>
using namespace std;

string s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (1) {
    getline(cin, s);
    if (s == ".") break;

    bool flag = true;
    vector<char> v;

    for (char c : s) {
      if (c == '(' || c == '[') {
        v.push_back(c);
      } else if (c == ')') {
        if (v.empty()) {
          flag = false;
          break;
        }
        char t = v.back();
        v.pop_back();
        if (t != '(') {
          flag = false;
          break;
        }
      } else if (c == ']') {
        if (v.empty()) {
          flag = false;
          break;
        }
        char t = v.back();
        v.pop_back();
        if (t != '[') {
          flag = false;
          break;
        }
      }
    }
    if (!v.empty()) {
      flag = false;
    }

    if (flag) {
      cout << "yes" << "\n";
    } else {
      cout << "no" << "\n";
    }
  }

  return 0;
}