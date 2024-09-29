#include <iostream>
#include <vector>
using namespace std;

int N, ans;
string s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    vector<int> v;
    for (int j = 0; j < s.size(); j++) {
      if (v.size() > 0 && v.back() == s[j]) {
        v.pop_back();
      } else {
        v.push_back(s[j]);
      }
    }
    if (v.size() == 0) {
      ans++;
    }
  }
  cout << ans;

  return 0;
}