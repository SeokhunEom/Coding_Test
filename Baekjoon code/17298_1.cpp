#include <iostream>
#include <vector>
using namespace std;

int N, A;
int ans[1000001];
vector<pair<int, int> > v;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A;
    while (!v.empty() && v.back().first < A) {
      ans[v.back().second] = A;
      v.pop_back();
    }
    v.push_back({A, i});
  }
  while (v.size()) {
    ans[v.back().second] = -1;
    v.pop_back();
  }

  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }

  return 0;
}