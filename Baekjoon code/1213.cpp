#include <iostream>
using namespace std;

string s, ans = "";
int arr[26];
int odd_cnt, odd_idx = -1;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  for (char c : s) {
    arr[c - 'A']++;
  }

  for (int i = 0; i < 26; i++) {
    if (arr[i] % 2 == 1) {
      odd_cnt++;
      odd_idx = i;
    }
  }
  if (odd_cnt >= 2) {
    cout << "I'm Sorry Hansoo";
    return 0;
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < arr[i] / 2; j++) {
      ans += 'A' + i;
    }
  }
  if (odd_idx != -1) {
    ans += 'A' + odd_idx;
  }
  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < arr[i] / 2; j++) {
      ans += 'A' + i;
    }
  }
  cout << ans;

  return 0;
}