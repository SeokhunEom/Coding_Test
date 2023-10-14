#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a;

  cin >> a;
  for(int i = 0; i < a; i++) {
    for(int j = 0; j < i; j++)
      cout << " ";
    for(int k = 0; k < a - i; k++)
      cout << "*";
    cout << endl;
  }
    
  return 0;
}