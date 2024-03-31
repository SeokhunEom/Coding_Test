#include <bits/stdc++.h>

using namespace std;

int T, A, B;
bool vis[10000];

int funcD(int n) { return (n * 2) % 10000; }
int funcS(int n) { return n == 0 ? 9999 : n - 1; }
int funcL(int n) { return (n % 1000) * 10 + n / 1000; }
int funcR(int n) { return (n % 10) * 1000 + n / 10; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; t++) {
    queue<pair<int, string>> q;

    cin >> A >> B;
    for (int i = 0; i < 10000; i++) vis[i] = false;
    q.push({A, ""});
    vis[A] = true;

    while (!q.empty()) {
      int cur = q.front().first;
      string curStr = q.front().second;
      q.pop();

      if (cur == B) {
        cout << curStr << '\n';
        break;
      }

      int next = funcD(cur);
      if (!vis[next]) {
        vis[next] = true;
        q.push({next, curStr + "D"});
      }

      next = funcS(cur);
      if (!vis[next]) {
        vis[next] = true;
        q.push({next, curStr + "S"});
      }

      next = funcL(cur);
      if (!vis[next]) {
        vis[next] = true;
        q.push({next, curStr + "L"});
      }

      next = funcR(cur);
      if (!vis[next]) {
        vis[next] = true;
        q.push({next, curStr + "R"});
      }
    }
  }

  return 0;
}
