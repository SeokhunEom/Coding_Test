#include <iostream>
#include <map>
using namespace std;

int N, M, n;
string s;
string arr[100001];
map<string, int> m;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> s;
    arr[i] = s;
    m[s] = i;
  }
  for (int i = 0; i < M; i++) {
    cin >> s;
    if (s[0] >= '0' && s[0] <= '9') {
      n = stoi(s);
      cout << arr[n] << "\n";
    } else {
      cout << m[s] << "\n";
    }
  }

  return 0;
}