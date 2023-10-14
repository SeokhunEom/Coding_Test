#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a;

  cin >> a;
  for(int i = 0; i < a; i++) {
    for(int j = 0; j <= i; j++)
      cout << "*";
    for(int k = 0; k < 2 * (a - i - 1); k++)
      cout << " ";
    for(int l = 0; l <= i; l++)
      cout << "*";
    cout << endl;
  }
  for(int i = 1; i < a; i++) {
    for(int j = 0; j < a - i; j++)
      cout << "*";
    for(int k = 0; k < 2 * i; k++)
      cout << " ";
    for(int l = 0; l < a - i; l++)
      cout << "*";
    cout << endl;
  }
    
  return 0;
}