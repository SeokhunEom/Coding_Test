#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, a[5001] = {0, }, t = 0;
  cin >> n >> k;
  cout << "<";
  for(int i = 0; i < n; i++) {
    int j = 0;
    while(1) {
      if(a[t] == 1) {
        if(t == n)
          t = 1;
        else
          t++;
        continue;
      }
      if(++j >= k)
        break;
      if(t == n)
        t = 1;
      else
        t++;
    }
    a[t] = 1;
    if(i != n - 1){
      if(t != n)
        cout << t  + 1<< ", ";
      else
        cout << 1 << ", ";
    }
    else{
      if(t != n)
        cout << t + 1;
      else
        cout << 1;
    }
  }
  cout << ">";

  return 0;
}