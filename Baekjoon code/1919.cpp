#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr_a[26] = {0, }, arr_b[26] = {0, }, r = 0;
  string a, b;

  cin >> a >> b;
  for(int i = 0; i < a.length(); i++)
    arr_a[a[i] - 'a']++;
  for(int i = 0; i < b.length(); i++)
    arr_b[b[i] - 'a']++;
  for(int i = 0; i < 26; i++) {
    if (arr_a[i] > arr_b[i])
      arr_a[i] = arr_a[i] - arr_b[i];
    else 
      arr_a[i] = arr_b[i] - arr_a[i];
  }
  for(int i = 0; i < 26; i++)
    r += arr_a[i];
  cout << r;

  return 0;
}