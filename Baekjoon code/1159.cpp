#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool flag = false;
int N;
string s;
int arr[26];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    arr[s[0] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (arr[i] >= 5) {
      cout << (char)(i + 'a');
      flag = true;
    }
  }
  if (flag == false) {
    cout << "PREDAJA";
  }

  return 0;
}