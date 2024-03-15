#include <bits/stdc++.h>

using namespace std;

int M, x;
bool arr[21];
string s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> s;
    if (s == "add") {
      cin >> x;
      arr[x] = true;
    } else if (s == "remove") {
      cin >> x;
      arr[x] = false;
    } else if (s == "check") {
      cin >> x;
      cout << (arr[x] ? 1 : 0) << "\n";
    } else if (s == "toggle") {
      cin >> x;
      arr[x] = arr[x] ? false : true;
    } else if (s == "all") {
      for (int j = 1; j <= 20; j++) arr[j] = true;
    } else if (s == "empty") {
      for (int j = 1; j <= 20; j++) arr[j] = false;
    }
  }

  return 0;
}
