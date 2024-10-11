#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
string s, t = "";
vector<string> v;

bool comp(string s1, string s2) {
  if (s1.size() > s2.size()) {
    return false;
  } else if (s1.size() < s2.size()) {
    return true;
  }
  return s1 < s2;
}

string func(string s) {
  if (s[0] != '0') return s;
  if (s == "0") return "0";

  string ret = "";
  for (int i = 1; i < s.size(); i++) {
    ret += s[i];
  }
  return func(ret);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (char c : s) {
      if (c >= '0' && c <= '9') {
        t += c;
      } else {
        if (t != "") {
          t = func(t);
          v.push_back(t);
        }
        t = "";
      }
    }
    if (t != "") {
      t = func(t);
      v.push_back(t);
      t = "";
    }
  }

  sort(v.begin(), v.end(), comp);
  for (string str : v) {
    cout << str << "\n";
  }

  return 0;
}