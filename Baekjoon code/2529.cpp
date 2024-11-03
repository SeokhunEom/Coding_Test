#include <iostream>
using namespace std;

int k;
char arr[10];
bool check[10];
string maxs = "";
string mins = "9876543210";

void dfs(int n, string s) {
  if (s.size() == k + 1) {
    maxs = max(maxs, s);
    mins = min(mins, s);
    return;
  }

  for (int i = 0; i <= 9; i++) {
    if (check[i]) continue;
    if (arr[s.size() - 1] == '>') {
      if (s.back() - '0' < i) continue;
    }
    if (arr[s.size() - 1] == '<') {
      if (s.back() - '0' > i) continue;
    }

    check[i] = true;
    s.push_back(i + '0');
    dfs(i, s);
    s.pop_back();
    check[i] = false;
  }
}

void func() {
  string s = "";

  for (int i = 0; i <= 9; i++) {
    check[i] = true;
    s.push_back(i + '0');
    dfs(i, s);
    s.pop_back();
    check[i] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }

  func();
  cout << maxs << '\n';
  cout << mins << '\n';

  return 0;
}