#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  deque <int> dq;
  cin >> t;
  while(t--) {
    string p;
    cin >> p;
    int n, a = 1, idx = -1;
    string s;
    cin >> n;
    cin >> s;
    int len_s = s.length();
    for(int i = 1; i < len_s - 1; i++){
      if(s[i] == ',')
        continue;
      else if(i + 1 < len_s && (s[i + 1] == ',' || s[i + 1] == ']'))
        dq.push_front(s[i] - 48);
      else if(i + 1 < len_s && (s[i + 2] == ',' || s[i + 2] == ']')){
        dq.push_front((s[i] - 48) * 10 + s[i + 1] - 48);
        i++;
      }
      else{
        dq.push_front(100);
        i += 2;
      }
    }
    int len_p = p.length();
    for(int i = 0; i < len_p; i++) {
      if(p[i] == 'R')
        idx *= -1;
      else if(p[i] == 'D') {
        if(dq.empty()) {
          cout << "error" << "\n";
          a = 0;
          break;
        }
        if(idx == 1)
          dq.pop_front();
        else 
          dq.pop_back();
      }
    }
    if(a) {
      cout << "[";
      int dq_size = dq.size();
      if(idx == 1) {
        while(dq_size--) {
          cout << dq.front();
          if(dq_size)
            cout << ",";
          dq.pop_front();
        }
        cout << "]" << "\n";
      }
      else {
        while(dq_size--) {
          cout << dq.back();
          if(dq_size)
            cout << ",";
          dq.pop_back();
        }
        cout << "]\n";
      }
    }
  }

  return 0;
}