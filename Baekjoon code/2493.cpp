#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a;
  stack<pair<int, int> > tower;
  cin >> n;
  tower.push({100000001, 0});
  for(int i = 0; i < n; i ++) {
    cin >> a;
    while (tower.top().first < a)
      tower.pop();
    cout << tower.top().second << " ";
    tower.push({a, i + 1});
  }

  return 0;
}