#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int result[1000000];
  stack<pair<int, int> >arr;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    while(!arr.empty() && arr.top().first < a) {
      result[arr.top().second] = a;
      arr.pop();
    }
    arr.push({a, i});
  }
  while(arr.size()) {
    result[arr.top().second] = -1;
    arr.pop();
  }
  for(int i = 0; i < n; i++)
    cout << result[i] << " ";

  return 0;
}