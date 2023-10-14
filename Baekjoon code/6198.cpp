#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long int num = 0;
  stack <pair<int, int> > building;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    int h;
    if(i != n)
      cin >> h;
    else
      h = 1000000001;
    while(!building.empty() && building.top().first <= h) {
      num += i - building.top().second - 1;
      building.pop();
    }
    building.push({h, i});
  }
  cout << num;

  return 0;
}