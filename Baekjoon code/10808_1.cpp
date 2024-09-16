#include <iostream>
using namespace std;

string s;
int arr[26];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    arr[s[i] - 'a']++;
  }
  for(int n: arr) {
    cout << n << ' ';
  }

  return 0;
}