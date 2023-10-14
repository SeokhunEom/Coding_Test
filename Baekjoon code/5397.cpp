#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string L;
    cin >> L;
    list<char> c = {};
    list<char>::iterator cursor = c.begin();
    for(int j = 0; j < L.length(); j++) {
      char a = L[j];
      if(a == '<') {
        if(cursor != c.begin())
          cursor--;
      }
      else if(a == '>') {
        if(cursor != c.end())
          cursor++;
      }
      else if(a == '-') {
        if(cursor != c.begin()){
          cursor --;
          cursor = c.erase(cursor);
        }
      }
      else 
        c.insert(cursor, a);
    }
    for(list<char>::iterator j = c.begin(); j != c.end(); j++)
      cout << *j;
    cout << endl;
  }

  return 0;
}