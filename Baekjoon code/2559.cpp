#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int N, K, temp, sum, ans = INT_MIN;
vector<int> v;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  for (int i = 0; i < K; i++) {
    sum += v[i];
  }
  for (int i = K; i < N; i++) {
    ans = max(ans, sum);
    sum += v[i] - v[i - K];
  }
  ans = max(ans, sum);

  cout << ans;

  return 0;
}