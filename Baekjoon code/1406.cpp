#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  char a, b;
  string s;
  list<char> arr;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    arr.push_back(s[i]);
  list<char>::iterator cursor = arr.end();
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    if(a == 'L') {
      if(cursor != arr.begin())
        cursor --;
    }
    else if (a == 'D') {
      if(cursor != arr.end())
        cursor ++;
    }
    else if (a == 'B') {
      if(cursor != arr.begin()){
        cursor --;
        cursor = arr.erase(cursor);
      }
    }
    else if (a == 'P') {
      cin >> b;
      arr.insert(cursor, b);
    }
  }
  for(list<char>::iterator i = arr.begin(); i != arr.end(); i++)
    cout << *i;

  return 0;
}