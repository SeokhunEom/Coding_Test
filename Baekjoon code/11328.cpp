#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, arr[26], temp;
  string a, b;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    if(a.length() != b.length()) {
      cout << "Impossible" << endl;
      continue;
    }
    fill(arr, arr + 26, 0);
    for(int j = 0; j < a.length(); j++)
      arr[a[j] - 'a']++;
    for(int j = 0; j < b.length(); j++)
      arr[b[j] - 'a']--;
    temp = 0;
    for(int j = 0; j < 26; j++) {
      if(arr[j]) {
        temp = 1;
        break;
      }
    }
    if(temp)
      cout << "Impossible" << endl;
    else
      cout << "Possible" << endl;
  }

  return 0;
}