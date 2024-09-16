#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
bool flag = false;
vector<int> v;
vector<int> ans;

void func(int depth) {
  if(ans.size() == 7) {
    int sum = 0;
    for(int n: ans) {
      sum += n;
    }
    if(sum == 100) {
      for(int n: ans) {
        cout << n << '\n';
      }
      flag = true;
    }
    return;
  }
  
  for(int i = depth; i < 9; i++) {
    ans.push_back(v[i]);
    func(i + 1);
    ans.pop_back();

    if(flag == true) {
      return;
    }
  }
}

int main(void) {
  for(int i = 0; i < 9; i++) {
    cin >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end());

  func(0);

  return 0;
}