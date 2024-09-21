#include <iostream>
using namespace std;

int N, star_idx;
string s, first, last;

bool check_pattern(string str) {
  if (str.size() < first.size() + last.size()) return false;

  string str_first = str.substr(0, star_idx);
  string str_last = str.substr(str.size() - last.size());

  if (str_first == first && str_last == last) return true;
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  cin >> s;
  star_idx = s.find('*');
  first = s.substr(0, star_idx);
  last = s.substr(star_idx + 1);

  for (int i = 0; i < N; i++) {
    cin >> s;
    cout << (check_pattern(s) ? "DA" : "NE") << '\n';
  }

  return 0;
}