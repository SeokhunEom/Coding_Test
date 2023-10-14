#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k, sum = 0;
  stack<int> arr;
  cin >> k;
  for(int i = 0; i < k; i++) {
    int a;
    cin >> a;
    if(a == 0)
      arr.pop();
    else
      arr.push(a);
  }
  int len = arr.size();
  for(int i = 0; i < len; i++) {
    sum += arr.top();
    arr.pop();
  }
  cout << sum;

  return 0;
}