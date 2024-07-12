#include <bits/stdc++.h>
using namespace std;

int n, len, t, idx;
int s[32769];
vector<int> s2;
int a[16];

int main(void) {
  cin >> n;
  len = 1 << n;
  for (int i = 0; i < len; i++) cin >> s[i];
  sort(s, s + len);

  s2.push_back(0);
  for (int i = 1; i < len; i++) {
    if (idx >= n) break;
    if (s[i] == 0) continue;

    a[idx++] = s[i];

    int prev_size = s2.size();
    for (int j = 0; j < prev_size; j++) s2.push_back(s2[j] + s[i]);
    int new_size = s2.size();

    for (int j = prev_size; j < new_size; j++) {
      for (int k = 0;; k++) {
        if (s[k] == s2[j]) {
          s[k] = 0;
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) cout << a[i] << " ";

  return 0;
}